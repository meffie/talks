#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/random.h>
#include <linux/base64.h>

MODULE_LICENSE("GPL");

static dev_t password_dev;
static struct class *password_class;
static struct cdev password_cdev;

static int password_len = 12;

static const int PASSWORD_LEN_MIN = 1;
static const int PASSWORD_LEN_MAX = 80;
static const int PASSWORD_RANDOM_BYTES = 60;

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

static const struct file_operations password_fops = {
    .owner = THIS_MODULE,
    .open = password_open,
    .release = password_release,
    .read = password_read,
    .write = password_write
};

static int password_chmod(struct device *dev, struct kobj_uevent_env *env)
{
    add_uevent_var(env, "DEVMODE=%#o", 0666);
    return 0;
}

static int __init password_init(void)
{
    pr_info("password: loading module\n");

    alloc_chrdev_region(&password_dev, 0, 1, "password");
    pr_info("password: major:minor is %d:%d\n", MAJOR(password_dev), MINOR(password_dev));

    password_class = class_create(THIS_MODULE, "password");
    password_class->dev_uevent = password_chmod;

    cdev_init(&password_cdev, &password_fops);
    password_cdev.owner = THIS_MODULE;

    cdev_add(&password_cdev, password_dev, 1);
    device_create(password_class, NULL, password_dev, NULL, "password");
    return 0;
}

static void __exit password_exit(void)
{
    pr_info("password: unloading module\n");
    device_destroy(password_class, password_dev);
    class_destroy(password_class);
    unregister_chrdev_region(password_dev, 1);
}

module_init(password_init);
module_exit(password_exit);
