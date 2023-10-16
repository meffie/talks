KVERSION := $(shell uname -r)
KBUILD   := /lib/modules/$(KVERSION)/build
SOURCE   := $(shell pwd)
obj-m    := password.o

all:
	make -C $(KBUILD) M=$(SOURCE) modules

clean:
	make -C $(KBUILD) M=$(SOURCE) clean
