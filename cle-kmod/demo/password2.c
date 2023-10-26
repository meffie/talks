#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");

static dev_t password_dev;
static struct class *password_class;
static struct cdev password_cdev;

static const struct file_operations password_fops = {
    .owner = THIS_MODULE,
};

static int __init password_init(void)
{
    pr_info("password: loading module\n");

    alloc_chrdev_region(&password_dev, 0, 1, "password");
    pr_info("password: major:minor is %d:%d\n", MAJOR(password_dev), MINOR(password_dev));

    password_class = class_create(THIS_MODULE, "password");

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
