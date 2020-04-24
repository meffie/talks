Second hello world rpm packaging.

This is a slightly more realistic example showing how to package built
from sources, distributed as a source tarball.


Put the sources in a tarball:

    $ make dist
    $ tar tzf hello-2.0.tar.gz
    hello-2.0/
    hello-2.0/hello.c
    hello-2.0/LICENSE
    hello-2.0/Makefile
    hello-2.0/configure

Copy to SOURCES:

    $ cp hello-2.0.tar.gz ~/rpmbuild/SOURCES

Change the spec.

Copy to SPECS:

    $ cp hello.spec ~/rpmbuild/SPECS/hello.spec

Build the RPMs:

    $ rpmbuild -ba ~/rpmbuild/SPECS/hello.spec

Install with `yum`.

    $ sudo yum install ~/rpmbuild/RPMS/x86_64/hello-2.0-1.el7.noarch.rpm
    Updated:
      hello.x86_64 0:2.0-1.el7

    $ hello

    $ rpm -qi hello


Clean up the workspace for the next example. Remove everything except the SRPMS.

    rm -rf ~/rpmbuild/{BUILD,BUILDROOT,RPMS,SOURCES,SPECS}

