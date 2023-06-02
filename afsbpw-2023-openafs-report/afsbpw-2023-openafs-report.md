---
title: OpenAFS Status Report
author: Michael Meffie, OpenAFS Release Team
date: June 14, 2023
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

Google Summer of Code 2022
--------------------------

* OpenAFS Participated in Goggle Summer of Code 2022
  - Arnie Jhingran: Stress test harness
  - Virkram Rajsitpal: Reverse Index lookup
  - https://www.openafs.org/gsoc/2022.html

* Not participating in 2023, planning to apply for 2024

OpenAFS Release Team Meetings
-----------------------------

* Stephan Wiesand, OpenAFS Release Manager

* Ben Kaduk, OpenAFS Guardian

* Every Thursday at 12:00 noon Eastern via IRC
  * channel #openafs-releaseteam
  * libra.chat

* Agenda:
  * Changes for OpenAFS Stable (1.8.x)
  * Changes for OpenAFS Development

Gerrit
------

* All code changes are reviewed on https://gerrit.openafs.org

* For information on how to submit code changes, see:

    https://wiki.openafs.org/devel/GitDevelopers/

* Changes for master should be based on the current master branch.

* Changes for stable must be submitted as stacks based on 1.8.x
  * Changes must already exist on the master branch
  * Limited refactoring patches may be accepted to allow for cleaner backports.
  * Please coordinate with the Release Team before submitting to stable branch on gerrit.

Buildbot
--------

* Performs test builds of each gerrit submission
  - buildbot.openafs.org is hosted by MIT
  - Community provided builders for various platforms
  - Ansible managed configuration
  - Molecule used for local testing
  - https://github.com/openafs-contrib/afsbotcfg

* New contributed builders in 2023
  - AlmaLinux 9
  - AIX 6
  - AIX 7
  - macos11
  - macos12

OpenAFS Releases
----------------

* 1.8.9       December 2022
* 1.8.10pre1  May 2023

OpenAFS 1.8.9
-------------

Platforms

* Linux 6.0 Support

* FreeBSD 12.3 support

OpenAFS 1.8.9 - Highights
-------------------------

* Reject negative inputs in the filesever FetchData RPC. (Previously, negative
  inputs resulted in the volume being taken offline.)

* Fix string buffer overflow in kernel module when queried with "cmdebug".

* Avoid more panics in the kernel module in failure conditions.

* Warn when server processes are started without keys.

* Avoid DNS lookups in fs commands when not needed (getcellstatus, checkservers, setcell).

* Red Hat RPMs: defer loading the OpenAFS kernel module until it is needed.


OpenAFS 1.8.10pre1 - Platforms
------------------------------

* Apple macOS 13 "Ventura" support

* Apple Silicon support

* Linux 6.3 support

* AIX 7 support


OpenAFS 1.8.10pre1 - Highights
------------------------------

* Take the readonly volume offline during "vos convertROtoRW"

* Improved error messages and diagnostics

* Add fs getfid -literal option for Unix clients

* Trim trailing slashes from paths given to "fs lsmount" and "fs flushmount"

* Fixed potential cache inconsistencies for symbolic link metadata

* More kernel panic avoidance and removed all strcpy() calls from kernel module

OpenAFS master branch
---------------------

* Support for newer platform levels upto:
    * AIX 7.2
    * Apple macOS 13
    * Apple Silicon
    * Linux 6.3 (with patches for Linux 6.4 RC)

* Support for newer compilers (clang-16 ang gcc-13)

OpenAFS master branch
---------------------

* Operational improvements:
    * Fixed potential cache inconsistencies for symlink metadata
    * Fixed pag buildup
    * Improved fs flush to invalidate Linux's cached dentries
    * Improved error messages and diagnostics

OpenAFS master branch
---------------------

* General code cleanup:
    * Replacement of string functions with safer alternatives,
      (e.g. strcpy => strlcpy, etc.)
    * Improved support for larger strings by using allocated memory
      instead of fixed sized buffers.
    * Removing obsolete and dead code, consolidating redundant code,
      etc.
    * Various fixes for memory leaks, range checking, validating
      pointers before use, out of memory conditions, potential panics
      due to memory
    * Improvements to the autoconf macros and build processes for detecting
      installed libraries, compiler flags and platform detection

Questions?
----------

Thank you
