---
title: OpenAFS Status Report
author: Michael Meffie, OpenAFS Release Team
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

OpenAFS 1.8.9 Highlights
------------------------

* Reject negative inputs in the filesever FetchData RPC. (Previously, negative
  inputs resulted in the volume being taken offline.)

* Fix string buffer overflow in kernel module when queried with "cmdebug".

* Avoid more panics in the kernel module in failure conditions.

* Warn when server processes are started without keys.

* Avoid DNS lookups in fs commands when not needed (getcellstatus, checkservers, setcell).

* Red Hat RPMs: defer loading the OpenAFS kernel module until it is needed.

* Linux 6.0 Support

* FreeBSD 12.3 support

OpenAFS 1.8.10pre1
------------------

* Apple macOS 13 (Ventura) support 

* Apple Silicon support

* Linux 6.3 support

* AIX 7 support

* Take the readonly volume offline during "vos convertROtoRW"

* Improved error messages and diagnostics

* Removed the obsolete kdump debugging tool

* Removed all strcpy() calls from kernel module.

* Trim trailing slashes from paths given to "fs lsmount" and "fs flushmount" (15242)

* Add fs getfid -literal option for Unix clients

* More kernel panic avoidance

* Fixed potential cache inconsistencies for symbolic link metadata


OpenAFS master branch
---------------------

Platforms


OpenAFS master branch
---------------------

Fixes

* Compare `RX_ACK_TYPE_ACK` as a bit-field

* New `RXAFS_StoreACL` (CVE-2018-7168)

* Improve performance with large number of PAGs

* Fix FID output format in cmdebug


OpenAFS master branch
---------------------

Features


OpenAFS master branch
---------------------

Clean up


Changes in Review
-------------------

* RxGK security class
  * Add client/server support

* Pthreaded Bosserver

* Pthreaded fs command

* Bosserver large string support

* Compiler support (gcc 12)

* and many more...

Questions?
----------

Thank you.
