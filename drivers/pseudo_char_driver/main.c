#include <linux/module.h>
#include <linux/init.h>
#include <linux/printk.h>
#include <linux/fs.h>
#include <linux/types.h>
#include "main.h"

/* Memory Area acting as the Pseudo Device */
char pseudo_device [DEVICE_MEM_SIZE];

/* Device numbers */
int scull_major = SCULL_MAJOR;
int scull_minor = 0;

/* Start function */
static int __init scull_init_module (void)
{
	// To store the return value for Error Handling.
	int res;

	// To store the Device number of the Pseudo Device.
	dev_t device_number = 0;

	/* Get the Device number */
	if (scull_major)
	{
		// If the Major number is provided, register the Device number.
		device_number = MKDEV(scull_major, scull_minor);
		res = register_chrdev_region (device_number, 1, "scull");
	}
	else
	{
		// If the Major number is not provided, dynamically allocate the Device number.
		res = alloc_chrdev_region (device_number, 0, 1, "scull");
		scull_major = MAJOR(device_number);
	}

	/* Error Handling */
	if (res < 0)
	{
		printk (KERN_WARNING "scull: Cannot obtain a Major number %d\n", scull_major);
		return result;
	}

	return 0;
}

/* End function */
static void __exit scull_cleanup_module (void)
{

}

/* Module registration */
module_init(scull_init_module);
module_exit(scull_cleanup_module);

/* Module description */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Prabhat Kiran");
MODULE_DESCRIPTION("Pseudo Character Device Driver Module")
