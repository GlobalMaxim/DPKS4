#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>

MODULE_LICENSE("Dual BSD/GPL");

static uint value = 1;
module_param(value, uint, S_IRUGO);
MODULE_PARM_DESC(value, "This parameter defines a number of output strings");

static int __init hello_init(void)
{
    if (value > 10)
    {
        printk(KERN_ERR "Error: parameter cannot be greater than 10\n");
        return -EINVAL;
    }

    if (!value || (value >= 5 && value <= 10))
        printk(KERN_WARNING "Warning: parameter is set to %u\n", value);

    uint i;
    for (i = 0; i < value; ++i)
        printk(KERN_NOTICE "Hello, world!!!\n");

    return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
    printk(KERN_NOTICE "Goodbye, world!!!\n");
}
module_exit(hello_exit);
