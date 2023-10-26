KBUILD   := /lib/modules/$(shell uname -r)/build
SOURCE   := $(shell pwd)
obj-m    := password1.o password2.o password3.o password4.o password5.o password6.o

modules:
	make -C $(KBUILD) M=$(SOURCE) modules

clean:
	make -C $(KBUILD) M=$(SOURCE) clean
