---
title: Data Version Numbers and the Cache
author: Michael Meffie, Sine Nomine Associates
date: June 14, 2023
abstract:

- In this talk, we will give a high level description of how AFS meta-data is
  used to provide data consistency for both read/write and read-only data.  We
  will show how to check the data version numbers on the clients and servers,
  what is cached on clients, when and how to flush the OpenAFS and Linux VFS
  caches when things go wrong, and present best practices for restoring data.
---

# Agenda

* Key AFS Metadata

* Reverting volumes with vos

* Recent improvements to `fs flush`

* New tool to tinker with AFS metadata

# AFS Metadata - File Id

* File Identifier (FID)
  - Volume Number (32 bits)
  - Vnode Number (32 bits)
  - Uniquifier (32 bits) (per volume counter)

* Each file, directory, symlink, and mount-point has a FID.

* Volume dumps include FIDs and Volume Uniquifier counter at the time of the dump

* `fs examine` or `fs getfid` to see the FIDs on clients

* `volscan` to see FIDs on servers

# AFS Metadata - Data Version Number

* Data Version Number (DV)
  - 64 bit counter per vnode object
  - Each file, directory, symlink, and mount-point has a DV.

* Incremented on the **server** when a vnode is changed

* Volume dumps include DVs at the time of the dump

* `volscan` to see DVs on servers

* `cmdebug` to show DVs on clients

# Example

    # Client A
    $ cd /afs/.example.com/test
    $ echo "hello" >hello
    $ fs getfid hello   # (changed to show dv)
    File hello (fid:536870918.2.2 dv:0.1) ...

    # Client B
    $ cd /afs/.example.com/test
    $ echo "hi" >hello

    # Client C
    $ fs getfid hello
    File hello (fid:536870918.2.2 dv:0.2) ...

# Reverting with vos restore

* Sometimes mistakes are made, and we want to roll
  back changes

* `vos restore` has an option to overwrite a volume

* This will also revert the metadata!
  - Data Versions go backwards!
  - Volume Uniq counter (can) go backwards!

* Best practice
  - Be sure to restore to a new volume
    and use regular commands to copy files into place.

# Scenario

1. Our `hello` file contains "hello" and has DV 1
2. A volume dump is saved
3. The file is changed to "hi" and now has DV 2
4. The file is cached (without callbacks) on clients as DV 2
5. The volume is reverted with
  - `vos restore -overwrite full`
6. The fileserver now has "hello" with DV 1
7. `hello` is changed to "bye" and now has DV 2 again
8. Some caches have the old DV 2 so will have stale content
9. The stale caches must be flushed with `fs flush*`


# fs flush

* `fs flush*` commands will flush caches, forcing the client
   to refetch data

* As of current master, `fs flush*` commands will also automatically
  flush the Linux dcache for AFS vnodes. (Gerrit 15391)

* As a last resort, it may be necessary to flush Linux VFS caches

    `# echo 3 > /proc/sys/vm/drop_caches`

    `$ sudo sysctl -q -w vm.drop_caches=3`

# Linux dcache flush example

        $ ls -l
        ls: cannot access foo: No such file or directory
        total 2
        drwxrwxr-x. 2 bin jdoe 2048 Apr  6 14:20 bar
        -?????????? ? ?   ?       ?            ? foo

        $ fs flush .  (no change)

        $ sudo sysctl -q -w vm.drop_caches=3
        $ ls -l
        total 3
        drwxrwxr-x. 2 bin jdoe  2048 Apr  6 14:20 bar
        -rw-rw-r--. 1 bin jdoe    29 Sep 22  2022 foo

# Linux dcache flush example

        $ ls -l
        ls: cannot access foo: No such file or directory
        total 2
        drwxrwxr-x. 2 bin jdoe 2048 Apr  6 14:20 bar
        -?????????? ? ?   ?       ?            ? foo

        $ fs flush .

        $ ls -l
        total 3
        drwxrwxr-x. 2 bin jdoe 2048 Apr  6 14:20 bar
        -rw-rw-r--. 1 bin jdoe   29 Sep 22  2022 foo

<!--
    $ ls mydir/hello
    ls: cannot access 'mydir/hello': No such file or directory

    $ vos restore ... -overwrite full

    $ ls mydir/hello
    ls: cannot access 'mydir/hello': No such file or directory

    $ fs flush mydir

    $ ls mydir/
    hello
-->

# bind mount Considerations

* Sometimes you want to **bind mount** files in AFS, for example
 when using docker

* The bind mounted vnodes are held by the kernel and will not change after a
  release even if the DV is bumped

* Be careful to bind mount the parents of files you expect to change (e.g., vos
  release)


# davol-tinker

* New command suite 'vol-tinker' to make low-level adjustments
to volumes directly on disk

* `davol-tinker dv-bump` command manipulates the DV of files in a volume

* This may be useful to force clients to invalidate caches and
re-fetch data (without running 'fs flush' on the clients directly)

* See https://gerrit.openafs.org/15397


# Thank you

Questions?


<!--
topics for the "data version" talk

* data version is critical meta-data

* high level description of how data versions are used

* how file, directory, and symlink data versions are used to
  achieve cache coherency

* best practices for restoring data

* when things go wrong

* how to view data version meta-data on clients and servers

* what is cached and how to flush the caches

* the Linux VFS and the negative dcache

Bonus content: how about the docker bind mount thing?
-->

<!--
Demo

    1 $ ls /afs/.example.com/test/mydir
    ls: cannot access '/afs/.example.com/test/mydir': No such file or directory

    1:$ cd /afs/.example.com/test
    1:$ mkdir mydir
    1:$ fs getfid mydir
    File mydir (fid:536870918.3.4 dv:0.0) located in cell example.com

    2:$ fs getfid mydir
    File mydir (fid:536870918.3.4 dv:0.0) located in cell example.com

    1:$ echo "hello world" >mydir/hello
    1:$ fs getfid mydir
    File mydir (fid:536870918.3.4 dv:0.1) located in cell example.com
    2:$ fs getfid mydir
    File mydir (fid:536870918.3.4 dv:0.1) located in cell example.com

1:$ vos dump test -file /var/tmp/test.dump
Dumped volume test in file /var/tmp/test.dump


    1:$ rm mydir/hello
    1:$ fs getfid mydir
    File mydir (fid:536870918.3.4 dv:0.2) located in cell example.com


    2:$ ls mydir/hello
    ls: cannot access 'mydir/hello': No such file or directory

    1:$ vos restore -server smoketest-debian11-1 -part a -name test -file /var/tmp/test.dump -overwrite full
    Volume exists; Will delete and perform full restore
    Restoring volume test Id 536870918 on server smoketest-debian11-1 partition /vicepa .. done
    Restored volume test on smoketest-debian11-1 /vicepa

    1:$ ls mydir/
    hello

    1:$ fs getfid mydir
    File mydir (fid:536870918.3.4 dv:0.1) located in cell example.com

    2:$ ls mydir/hello
    ls: cannot access 'mydir/hello': No such file or directory

    2:$ fs getfid mydir
    File mydir (fid:536870918.3.4 dv:0.1) located in cell example.com

    2:$ fs getfid mydir/hello
    fs: File 'mydir/hello' doesn't exist

    2:$ fs flush mydir
    2:$ fs getfid mydir/hello
    File mydir/hello (fid:536870918.2.5 dv:0.1) located in cell example.com
    2:$ ls mydir

    d460b616eb LINUX: Make 'fs flush*' invalidate dentry
-->
