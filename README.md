# What is Linux Kernel Module?

Linux Kernel Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. They extend the functionality of the kernel without the need to reboot the system.

It's possible to write drivers for devices that aren't supported by the kernel, or to add new system calls, or even to add support for a different filesystems.

## What this repository is about?

I was playing with the idea of mapping a folder to an Azure Storage Account, so all the files in that folder would be uploaded to the cloud automatically.

So, to build some kind of a storage driver, I decided to start with a simple Linux Kernel Module that would map a folder to an Azure Storage Account, based on a configuration file.

## Details about the module

[src/azure_storage.c](src/azure_storage.c) is the main file of the module, it contains the implementation of the module.

`MODULE_LICENSE()` is the license of the module, it's required to load the module into the kernel.
`MODULE_AUTHOR()` is the author of the module.
`MODULE_DESCRIPTION()` is the description of the module.

`module_init()` is the function that will be called when the module is loaded into the kernel.

`module_exit()` is the function that will be called when the module is unloaded from the kernel.

`pr_info()` is the function that will print a message to the kernel log.

[src/Makefile](src/Makefile) is the Makefile used to build the module.

`obj-m` is a variable in the Makefile that specifies the name of the module to be built. In our case, it's set to `azure_storage.o`, which means the output of the build will be a module named `azure_storage`. This is used when building Linux Kernel Modules.

`all:` is a target in the Makefile, it's the default target, so when you run `make` without specifying a target, it will run the `all` target.

With the `all` target, we're telling the Makefile to build the module `azure_storage` using the source file `azure_storage.c`

`clean:` is a target in the Makefile, it's used to clean the output of the build.

`unload` is a target in the Makefile, it's used to unload the module from the kernel.

`sudo rmmod azure_storage` is the command used to unload the module from the kernel.
