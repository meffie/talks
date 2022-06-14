---
title: OpenAFS Status Report
authors:
 - Ben Kaduk, OpenAFS Guardian
 - Stephan Wiesand, OpenAFS Release Manager
 - Michael Meffie, OpenAFS Release Team
date: June 14, 2022
abstract:
  - Updates on work that has been done for the OpenAFS stable release branches,
    work that is merged to the main development branch but not expected to be
    incorporated into the current stable release branches, and the status of
    planned future work.
---

Objectives
----------

* Updates on work done for the OpenAFS stable release branches

* Report on work merged to the main development branch

* Status of planned future work


OpenAFS Release Team Meetings
-----------------------------

* Every Thursday at 12:00 noon Eastern via Jabber

* Agenda:
  * Changes for OpenAFS Stable
  * Changes for OpenAFS 1.9.x/master

* Logs:

    https://conference.openafs.org/release-team@conference.openafs.org/

Gerrit
------

* All code changes are reviewed on https://gerrit.openafs.org

* For information on how to submit code changes, see:

    https://wiki.openafs.org/devel/GitDevelopers/

* Changes for master should be based on the current master branch

* Changes for stable must be submitted as stacks based on 1.8.x
  * changes must already exist on the master branch
  * limited refactoring patches may be accepted to allow for cleaner backports
  * please coordinate with the Release Team before submitting to stable branch on gerrit

Buildbot
--------

* Performs test builds of each gerrit submission
  - buildbot.openafs.org is hosted by MIT
  - Community provided builders for various platforms

* Upgraded to Buildbot 3.5.0 in 2022
  - Configuration is Ansible managed now
  - New builder names to distinguish gerrit triggered from nightlies
  - https://github.com/openafs-contrib/afsbotcfg

* New contributed builders in 2022
  - openSUSE 15
  - FreeBSD 12
  - Debian 11
  - Fedora 35

OpenAFS Releases
----------------

Recent OpenAFS Releases

* 1.8.8    July, 2021
* 1.8.8.1  December, 2021
* 1.8.8.2/1.8.9  In progress
* Next Stable Series (perhaps 1.10)

OpenAFS 1.8.8
-------------

Highlights

* Avoid Rx calls getting stuck on the incoming call queue
* Avoid a possible salvageserver deadlock
* Avoid client connections hanging forever when the server is restarted
* Improved documentation, diagnostics and error messages
* Fixes for recent c compilers
* Avoid potential salvager crashes
* Avoid erratic vlserver behaviour due to overflowing the maximum VLDB size of 2 GB
* Fixed a slow kernel memory leak triggered by retrieving tokens

(continued)

OpenAFS 1.8.8 (continued)
-------------------------

* Fix 'pts mem -expandgroups' failure when supergroups are enabled
* Take read-only volumes offline during read-only to read-write conversion
* Avoid inconsistent volume states due to interrupted rename operations
* Support deleting non-DES keys with asetkey
* Improved ubik performance and robustness
* Avoid flooding servers with NAT pings
* Avoid panics during client startup or shutdown
* Avoid buffer overflows by one character in the "bos" client program

(continued)

OpenAFS 1.8.8 (continued)
-------------------------

* Linux
  * Support Linux kernel 5.13
  * Fix crash when running on Crowdstrike Falcon
  * Fix crash when reading from /proc/fs/openafs/CellServDB before afsd has started
  * Fix more getcwd() failures

* macOS
  * Support macOS 11.0 "Big Sur"

* FreeBSD
  * Support releases 11.2, 12.1, 12.2

(and more, see NEWS)

1.8.8.1
-------

* Support Linux kernels 5.14, 5.15 and 5.16
* Support building on FreeBSD 12
* Support building on Solaris with Solaris Studio 12.6

Changes for 1.8.8.2/1.8.9
------------------------

* Support Linux version 5.17
* Avoid unnecessary cell DNS lookups
* Cleanup and refactoring changes for clean backports
* Changes for FreeBSD 12.3 support
* Changes for improved C compiler support (gcc 11, clang 13)
* Update c-tap-harness (unit tests) to support verbose output



OpenAFS master branch
---------------------

Platforms

* Linux 5.18 support

* MacOS 12.0 "Monterey" support

* FBSD 12 support

* Build support for AIX 7.2

OpenAFS master branch
---------------------

Fixes/Changes

* Compare `RX_ACK_TYPE_ACK` as a bit-field

* New `RXAFS_StoreACL` (CVE-2018-7168)

* Improve performance with large number of PAGs

* Fix FID output format in cmdebug


OpenAFS master branch
---------------------

Features

* Log a warning if the bosserver is not started in restricted mode

* Support `fs -literal` option (non-Windows)

* Support unified error number lookup in `translate_et` (non-Windows)

* Trim trailing path slashes in `fs lsmount` and `fs flushmount`

* Convert from unsafe to safe string functions
  * kernel module
  * bos client

* Compiler support
  * clang 13, 14
  * gcc 12

OpenAFS master branch
---------------------

Clean up

* Remove afsinstall (obsolete install scripts)

* Remove kdump (obsolete kernel module debugging)

* Remove obsolete autoconf macros (build system)

* Remove IRIX pre-65 code

* Set oldest supported Linux kernel version to 2.6.18

* Fix issues detected by clang static analyzer


Changes in Review
-------------------

* RxGK security class
  * Add client/server support

* Linux 5.18 support
  * replace readpages with readahead

* Pthreaded Bosserver

* Pthreaded fs command

* Bosserver large string support

* Compiler support (gcc 12)

* and many more...

Questions?
----------

Thank you.
