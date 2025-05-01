/* Needed by all the Kernel Modules */
#include <linux/module.h>
/* Needed for all the Macros */
#include <linux/init.h>
/* Needed for pr_info() function */
#include <linux/printk.h>

/* Start function */
static int __init hello_world_init (void)
{
	// Initialization code for the Module.
	pr_info ("Hello World\n");

	// Return 0 for Success is mandatory.
	return 0;
}

static void __exit hello_world_cleanup (void)
{
	// Clean-up code for the Module.
	pr_info ("Good-Bye World\n");
}

/* Module registration */
module_init(hello_world_init);
module_exit(hello_world_cleanup);

/* Module description */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Prabhat Kiran");
MODULE_DESCRIPTION("Hello World for Kernel Module");
MODULE_INFO(Board, "BeagleBone Black");
