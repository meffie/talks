
#include <linux/base64.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/ioctl.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/random.h>
#include <linux/sysctl.h>


static int password_length = 12;
static int password_length_min = 1;
static int password_length_max = 80;

static int password_major = 0;
static struct class *password_class = NULL;
static struct cdev password_cdev = {};

static const unsigned int PASSWORD_GET_LENGTH = _IOR('p', 0, int);
static const unsigned int PASSWORD_SET_LENGTH = _IOW('p', 1, int);

/*
 * File operations.
 */

static int password_open(struct inode *inode, struct file *file)
{
    pr_info("password: open\n");
    return 0;
}

static int password_release(struct inode *inode, struct file *file)
{
    pr_info("password: release\n");
    return 0;
}

static long password_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)

{
    int rc;
    int __user *buffer = (int __user *)arg;
    int len;

    pr_info("password: ioctl(cmd=0x%x, arg=%lu)\n", cmd, arg);
    switch (cmd) {
    case PASSWORD_GET_LENGTH:
        pr_info("password: get length: %d\n", password_length);
        rc = put_user(password_length, buffer);
        pr_info("password: put_user() = %d\n", rc);
        break;
    case PASSWORD_SET_LENGTH:
        rc = get_user(len, buffer);
        if (rc != 0 || len < password_length_min || len > password_length_max) {
            rc = -EINVAL;
        } else {
            password_length = len;
            pr_info("password: set length: %d\n", password_length);
            rc = 0;
        }
        break;
    default:
        pr_warn("password: unknown ioctl cmd=0x%x\n", cmd);
        rc = 0;  /* -EINVAL */
    }
    return rc;
}

static ssize_t password_read(struct file *file, char __user *buffer, size_t count, loff_t *offset)
{
    size_t bytes_read = 0;
    u8 random[60];     /* Should be a multiple of 6 */
    char password[80]; /* Must be 4/3 * sizeof(random) */

    if (*offset > 0) {
        return bytes_read;
    }

    get_random_bytes(random, sizeof(random));
    base64_encode(random, sizeof(random), password);

    if (count > password_length) {
        if (copy_to_user(buffer, password, password_length)) {
            return -EFAULT;
        }
        bytes_read = password_length;

        if (copy_to_user(buffer + bytes_read, "\n", 1)) {
            return -EFAULT;
        }
        bytes_read++;
    }

    *offset = bytes_read;
    return bytes_read;
}

static ssize_t password_write(struct file *file, const char __user *buf, size_t count, loff_t *offset)
{
    pr_info("password: write\n");
    return 0;
}

static const struct file_operations password_fops = {
    .owner = THIS_MODULE,
    .open = password_open,
    .release = password_release,
    .unlocked_ioctl = password_ioctl,
    .read = password_read,
    .write = password_write
};

/*
 * Module init and exit.
 */

#ifdef CONFIG_SYSCTL

static struct ctl_table password_sysctl_table[] = {
    {
        .procname        = "password_length",
        .data            = &password_length,
        .maxlen          = sizeof(int),
        .mode            = 0666,
        .proc_handler    = proc_dointvec_minmax,
        .extra1          = &password_length_min,
        .extra2          = &password_length_max,
    },
    {}
};

static struct ctl_table_header *password_table_header;
#endif /* CONFIG_SYSCTL */

static int password_uevent(struct device *dev, struct kobj_uevent_env *env)
{
    add_uevent_var(env, "DEVMODE=%#o", 0666);
    return 0;
}

static int __init password_init(void)
{
    int error;
    dev_t dev;
    struct device *device;

    pr_info("password: loading module\n");
    pr_info("password: PASSWORD_GET_LENGTH = 0x%x\n", PASSWORD_GET_LENGTH);
    pr_info("password: PASSWORD_SET_LENGTH = 0x%x\n", PASSWORD_SET_LENGTH);

#ifdef CONFIG_SYSCTL
    password_table_header = register_sysctl_table(password_sysctl_table);
    if (IS_ERR(password_table_header)) {
        pr_err("password: register_sysctl_table failed: %d\n", error);
        goto out0;
    }
#endif

    error = alloc_chrdev_region(&dev, 0, 1, "password");
    if (error < 0) {
        pr_err("password: failed to allocate char device region: %d\n", error);
        goto out1;
    }

    password_major = MAJOR(dev);
    pr_info("password: major is %d\n", password_major);

    password_class = class_create(THIS_MODULE, "password");
    if (IS_ERR(password_class)) {
        error = PTR_ERR(password_class);
        pr_err("password: failed to create class: %d\n", error);
        goto out2;
    }
    password_class->dev_uevent = password_uevent;

    cdev_init(&password_cdev, &password_fops);
    password_cdev.owner = THIS_MODULE,
    cdev_add(&password_cdev, MKDEV(password_major, 0), 1);

    device = device_create(password_class, NULL, MKDEV(password_major, 0), NULL, "password");
    if (IS_ERR(device)) {
        error = PTR_ERR(device);
        pr_err("password: failed to create device: %d\n", error);
        goto out3;
    }

    return 0;

out3:
    device_destroy(password_class, MKDEV(password_major, 0));
    class_destroy(password_class);
out2:
    unregister_chrdev_region(MKDEV(password_major, 0), MINORMASK);
out1:
#ifdef CONFIG_SYSCTL
    unregister_sysctl_table(password_table_header);
#endif
out0:
    return error;
}

static void __exit password_exit(void)
{
    pr_info("password: unloading module\n");

    device_destroy(password_class, MKDEV(password_major, 0));
    class_destroy(password_class);
    unregister_chrdev_region(MKDEV(password_major, 0), MINORMASK);
#ifdef CONFIG_SYSCTL
    unregister_sysctl_table(password_table_header);
#endif
}


module_init(password_init);
module_exit(password_exit);

MODULE_LICENSE("GPL");
