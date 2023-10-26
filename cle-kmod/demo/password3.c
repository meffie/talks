#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");

static dev_t password_dev;
static struct class *password_class;
static struct cdev password_cdev;

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
    char *hello = "Hello World!\n";
    size_t len = strlen(hello);

    pr_info("password: read: offset=%lld\n", *offset);

    if (*offset > 0) {
        return bytes_read;
    }

    if (count > len) {
        if (copy_to_user(buffer, hello, len)) {
            return -EFAULT;
        }
        bytes_read = len;
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
    .write = password_write,
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
