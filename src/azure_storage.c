#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Engin Polat");
MODULE_DESCRIPTION("A simple kernel module to map a local directory to Azure Blob Storage");

static int __init module_init(void) {
  pr_info("Azure Storage Module loaded to memory\n");
  return 0;
}

static void __exit module_exit(void) {
  pr_info("Azure Storage Module unloaded from memory\n");
}

module_init(module_init);
module_exit(module_exit);
