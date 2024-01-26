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

## Instructions to prepare the environment

> **Note:** I'm using WSL2 on my machine, this repository is based on the [WSL2-Linux-Kernel](https://github.com/microsoft/WSL2-Linux-Kernel)

- Install required packages:

```bash
sudo apt install build-essential flex bison libssl-dev libelf-dev git dwarves -y
```

- Clone WSL2 Linux Kernel source code from the official repository:

```bash
git clone https://github.com/microsoft/WSL2-Linux-Kernel.git
cd WSL2-Linux-Kernel
```

- Copy the configuration file from the running kernel:

```bash
cp Microsoft/config-wsl .config
```

- Build the kernel:

```bash
make -j $(expr $(nproc) - 1)
```

> At this point, you can go grab a coffee ☕, it will take a while to build the kernel.
>
> When it's done, new kernel can be found at: `./arch/x86/boot/bzImage`

- Copy the new kernel to the WSL2 root folder:

```bash
cp ./arch/x86/boot/bzImage /mnt/c/Users/{user}/
```

- Create/update the WSL2 configuration file (`%UserProfile%\\.wslconfig`):

```bash
[wsl2]
kernel=C:\\Users\\{user}\\bzimage
```

- Restart WSL2:

```powershell
wsl --shutdown

wsl
```

- Check the new kernel version:

```bash
uname -r
```

## Instructions to build the module

- Run `make` to build the module:

```bash
make
```

- To load the module into the kernel, run:

```bash
sudo insmod azure_storage.ko
```

- To check the kernel log, run:

```bash
dmesg | tail -5
```

- You should see something like this:

```bash
[  123.456789] Azure Storage Module loaded to memory
```

- To unload the module from the kernel, run:

```bash
make unload
```

- To check the kernel log, run:

```bash
dmesg | tail -5
```

- You should see something like this:

```bash
[  123.456789] Azure Storage Module unloaded from memory
```

## Next steps

Now we have a simple Linux Kernel Module that can be loaded and unloaded into the kernel.

The next step is to implement the logic to map a folder to an Azure Storage Account, based on a configuration file 👍
