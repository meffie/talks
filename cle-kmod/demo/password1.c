#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init password_init(void)
{
    pr_info("password: loading module\n");
    return 0;
}

static void __exit password_exit(void)
{
    pr_info("password: unloading module\n");
}

module_init(password_init);
module_exit(password_exit);
