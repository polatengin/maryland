obj-m:=azure_storage.o

all:
				make -C $(shell pwd)/../WSL2-Linux-Kernel M=$(shell pwd) modules

clean:
				make -C $(shell pwd)/../WSL2-Linux-Kernel M=$(shell pwd) clean

unload:
				rm -rf .Makefile.swp .Module.symvers.cmd .azure_storage.ko.cmd .azure_storage.mod.cmd .azure_storage.mod.o.cmd .azure_storage.o.cmd .modules.order.cmd Module.symvers azure_storage.ko azure_storage.mod azure_storage.mod.c azure_storage.mod.o azure_storage.o modules.order
				sudo rmmod azure_storage
