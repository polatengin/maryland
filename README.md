# What is Linux Kernel Module?

Linux Kernel Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. They extend the functionality of the kernel without the need to reboot the system.

It's possible to write drivers for devices that aren't supported by the kernel, or to add new system calls, or even to add support for a different filesystems.

## What this repository is about?

I was playing with the idea of mapping a folder to an Azure Storage Account, so all the files in that folder would be uploaded to the cloud automatically.

So, to build some kind of a storage driver, I decided to start with a simple Linux Kernel Module that would map a folder to an Azure Storage Account, based on a configuration file.
