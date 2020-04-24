SRPM examples

Case 1: We have the SRPM and want rebuild as is:

    $ rpmbuild --rebuild ~/rpmbuild/SRPMS/hello-2.0-1.el7.src.rpm


Case 2: We have the SRPM and want to patch and rebuild (new release)

First install the SRPM, **not** as root, to extact the sources.

    $ rpm -i ~/rpmbuild/SRPMS/hello-2.0-1.el7.src.rpm
    $ tree ~/rpmbuild
    /home/user/rpmbuild/
    ├── SOURCES
    │   └── hello-2.0.tar.gz
    ├── SPECS
    │   └── hello.spec
    └── SRPMS
        ├── hello-1.0-1.el7.src.rpm
        └── hello-2.0-1.el7.src.rpm

Extract the source files:

    $ tar xvzf ~/rpmbuild/SOURCES/hello-2.0.tar.gz
    hello-2.0/
    hello-2.0/hello.c
    hello-2.0/LICENSE
    hello-2.0/Makefile
    hello-2.0/configure

Backup the original code and make our change.

    $ cd hello-2.0
    $ cp hello.c hello.c.orig
    $ vi hello.c

Create our patch and put it in SOURCES.

    $ diff -u hello.c.orig hello.c > ~/rpmbuild/SOURCES/mychange.patch

(In the real world, we'd likely be using git. And build and check
before trying to repackage.)

Edit the spec file to bump the release and patch the code.

    Release: 2%{?dist}        <- change from 1 to 2
    Source0: ...
    Patch0: mychange.patch    <- add line

    %prep
    %setup
    %patch0                   <- add line

Build the packages:

    $ rpmbuild -ba ~/rpmbuild/SPECS/hello.spec

Upgrade to the new release.

    $ sudo yum install ~/rpmbuild/RPMS/x86_64/hello-2.0-2.el7.x86_64.rpm
    $ hello
    Howdy world!
