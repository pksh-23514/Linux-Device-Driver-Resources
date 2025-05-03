# Main Build Dependency for the Linux Kernel Module
obj-m := main.o

# Set the Target Architecture
ARCH=arm

# Set the Cross-Compiler
CROSS_COMPILE=arm-linux-gnueabihf-

# Set the Path for the Kernel Source files location of the Target on the Host
KERN_DIR = /workdir/linux_source_BBB_ver/

# Set the Path for the Kernel Source files location on the Host
HOST_KERN_DIR = /lib/modules/$(shell uname -r)/build/

# Make Recipe for the Target Linux Kernel Module Build
all:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) modules

# Make Recipe for the Linux Kernel Module Removal
clean:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) clean
	make -C $(HOST_KERN_DIR) M=$(PWD) clean

# Make Recipe for the Linux Kernel Module Help
help:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) help

# Make Recipe for the Host Linux Kernel Module Build
host:
	make -C $(HOST_KERN_DIR) M=$(PWD) modules
