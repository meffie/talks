.PHONY: all clean install dist distclean

all: hello

hello: hello.o
	gcc -o hello hello.o

hello.o: hello.c
	gcc -c hello.c -Wall -Werror -g -O0

clean:
	rm -rf hello hello.o

install:
	mkdir -p $(DESTDIR)/usr/bin
	install -m 0755 hello $(DESTDIR)/usr/bin/hello

dist:
	mkdir /tmp/hello-2.0
	cp hello.c /tmp/hello-2.0
	cp LICENSE /tmp/hello-2.0
	cp Makefile /tmp/hello-2.0
	cp configure /tmp/hello-2.0
	tar -C /tmp -czf hello-2.0.tar.gz hello-2.0
	rm -rf /tmp/hello-2.0

distclean: clean
	rm -rf hello-2.0.tar.gz

