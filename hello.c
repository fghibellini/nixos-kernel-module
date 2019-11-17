#include <linux/module.h>
#define MODULE_NAME "hello"
static int __init hello_init(void)
{
    printk(KERN_INFO "hello world!");
    return 0;
}
static void __exit hello_cleanup(void) {}
module_init(hello_init);
module_exit(hello_cleanup);
