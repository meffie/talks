Hello world rpm packaging.

Prereqs:

    $ sudo yum install bash rpm-build rpm-devel rpmlint rpmdevtools

Write our example program. In this example we package a shell script.

    $ cat hello.sh
    #!/bin/bash
    echo "Hello world"
    $ chmod +x hello.sh
    $ ./hello.sh
    Hello world

Copy to SOURCES:

    $ mkdir -p ~/rpmbuild/SOURCES
    $ cp hello.sh ~/rpmbuild/SOURCES/hello-1.0.sh

Run `rpmdev-newspec` to create a new spec file:

    $ rpmdev-newspec hello.spec
    (Saved as hello.spec.template in this directory.)

Fill in the spec file.
(See: `diff -u hello.spec.template hello.spec`)

Copy to SPECS:

    $ mkdir -p ~/rpmbuild/SPECS
    $ cp hello.spec ~/rpmbuild/SPECS/hello.spec

Build the RPMs:

    $ rpmbuild -ba ~/rpmbuild/SPECS/hello.spec

Install with `yum`.

    $ sudo yum install ~/rpmbuild/RPMS/noarch/hello-1.0-1.el7.noarch.rpm

    $ hello
    Hello world

    $ rpm -qi hello

    $ yum whatprovides /usr/bin/hello
