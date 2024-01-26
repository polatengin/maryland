#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Engin Polat");
MODULE_DESCRIPTION("A simple kernel module to map a local directory to Azure Blob Storage");

static int __init module_init(void) {
  pr_info("Azure Storage Module loaded to memory\n");
  return 0;
}


module_init(module_init);
