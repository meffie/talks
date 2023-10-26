#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/random.h>
#include <linux/base64.h>
#include <linux/ioctl.h>
#include <linux/sysctl.h>

MODULE_LICENSE("GPL");

static dev_t password_dev;
static struct class *password_class;
static struct cdev password_cdev;

static int password_len = 12;

static const int PASSWORD_LEN_MIN = 1;
static const int PASSWORD_LEN_MAX = 80;
static const int PASSWORD_RANDOM_BYTES = 60;

static const unsigned int PASSWORD_GET_LEN = _IOR('p', 0, int);
static const unsigned int PASSWORD_SET_LEN = _IOW('p', 1, int);

static int password_len_min = PASSWORD_LEN_MIN;
static int password_len_max = PASSWORD_LEN_MAX;
static struct ctl_table password_table[] = {
    {
        .procname       = "password_len",
        .data           = &password_len,
        .maxlen         = sizeof(int),
        .mode           = 0666,
        .proc_handler   = proc_dointvec_minmax,
        .extra1         = &password_len_min,
        .extra2         = &password_len_max,
    },
    {},
};
static struct ctl_table_header *password_header;

/* File operations */
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

static ssize_t password_read(struct file *file, char __user *buffer, size_t count, loff_t *offset)
{
    ssize_t bytes_read = 0;
    u8 random[PASSWORD_RANDOM_BYTES];
    char password[PASSWORD_LEN_MAX];

    pr_info("password: read: offset=%lld\n", *offset);

    if (*offset > 0) {
        return bytes_read;
    }

    get_random_bytes(random, sizeof(random));
    base64_encode(random, sizeof(random), password);

    if (count > password_len) {
        if (copy_to_user(buffer, password, password_len)) {
            return -EFAULT;
        }
        if (copy_to_user(buffer + password_len, "\n", 1)) {
            return -EFAULT;
        }
        bytes_read = password_len + 1;
    }

    *offset += bytes_read;
    return bytes_read;
}

static ssize_t password_write(struct file *file, const char __user *buffer, size_t count, loff_t *offset)
{
    pr_info("password: write\n");
    return 0;
}

static long password_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int rc;
    int __user *buffer = (int __user *)arg;
    int tmp;

    pr_info("password: ioctl(cmd=0x%x, arg=%lu)\n", cmd, arg);

    switch (cmd) {
    case PASSWORD_GET_LEN:
        rc = put_user(password_len, buffer);
        break;
    case PASSWORD_SET_LEN:
        rc = get_user(tmp, buffer);
        if (rc == 0) {
            if (tmp < PASSWORD_LEN_MIN || tmp > PASSWORD_LEN_MAX) {
                rc = -EINVAL;
            } else {
                password_len = tmp;
            }
        }
        break;
    default:
        pr_warn("password: unknown ioctl 0x%x\n", cmd);
        rc = 0; /* -EINVAL */
    }

    return rc;
}

static const struct file_operations password_fops = {
    .owner = THIS_MODULE,
    .open = password_open,
    .release = password_release,
    .read = password_read,
    .write = password_write,
    .unlocked_ioctl = password_ioctl,
};

static int password_chmod(struct device *dev, struct kobj_uevent_env *env)
{
    add_uevent_var(env, "DEVMODE=%#o", 0666);
    return 0;
}

static int __init password_init(void)
{
    pr_info("password: loading module\n");

    pr_info("password: PASSWORD_GET_LEN=0x%x\n", PASSWORD_GET_LEN);
    pr_info("password: PASSWORD_SET_LEN=0x%x\n", PASSWORD_SET_LEN);

    alloc_chrdev_region(&password_dev, 0, 1, "password");
    pr_info("password: major:minor is %d:%d\n", MAJOR(password_dev), MINOR(password_dev));

    password_class = class_create(THIS_MODULE, "password");
    password_class->dev_uevent = password_chmod;

    cdev_init(&password_cdev, &password_fops);
    password_cdev.owner = THIS_MODULE;

    cdev_add(&password_cdev, password_dev, 1);
    device_create(password_class, NULL, password_dev, NULL, "password");

    password_header = register_sysctl_table(password_table);

    return 0;
}

static void __exit password_exit(void)
{
    pr_info("password: unloading module\n");
    unregister_sysctl_table(password_header);
    device_destroy(password_class, password_dev);
    class_destroy(password_class);
    unregister_chrdev_region(password_dev, 1);
}

module_init(password_init);
module_exit(password_exit);
