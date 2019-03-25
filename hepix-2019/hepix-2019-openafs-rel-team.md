Title: OpenAFS Release Team Report
Author: Michael Meffie
Date: March 25, 2019

OpenAFS Release Team
====================

* Weekly meetings via jabber on Fridays
  - jabber: release-team@conference.openafs.org
  - email: release-team@openafs.org
* Regular participants
  - Stephan Wiesand, Release Manager - DESY
  - Benjamin Kaduk
  - Mark Vitale
  - Michael Meffie
* Notes posted to openafs-devel@openafs.org
* Please join us to discuss OpenAFS releases

OpenAFS Contributors
====================

Commit authors since 1.8.0:

    Anders Kaseorg   Karl Behler
    Andrew Deason    Marcio Barbosa
    Benjamin Kaduk   Mark Vitale
    Caitlyn Marko    Michael Lass
    Cheyenne Wills   Michael Meffie
    Christof Hanke   Pat Riehecky
    Damien Diederen  Perry Ruiter
    Ian Wienand      Peter Foley
    Jeffrey Altman   Seth Forshee
    Joe Gorse        Stephan Wiesand

1.8 Stable Series
========================

* 1.8.x "new" stable
* Platform support
* Security fixes
* Bug fixes
* Selected improvements from the master branch
* Changes are pulled up from master branch

1.6 Stable Series
========================

* 1.6.x "old" stable continues to be supported
* No end-of-life target date at this time
* Platform support
* Security fixes
* Neccessary bug fixes
* Changes are pulled up from 1.8.x releases

OpenAFS 1.8.1
=============

* OpenAFS 1.8.1
  * 64-bit ARM client support
  * Fixes for FreeBSD
  * Regression fixes
    * Fix shared library exports
    * Fix volume callbacks regression when running vos release
    * Fix regression (panic) when cache bypass is enabled
    * Fix vldb-check regression
  * and more ... see NEWS
* OpenAFS 1.8.1.1
  * Support Linux 4.18

Security Advisories
===================

Security Releases: 1.8.2, 1.6.23

* OPENAFS-SA-2018-001
  * Volume-level data replacement via unauthenticated butc (backups) connections
* OPENAFS-SA-2018-002
  * Information leakage from uninitialized RPC output variables
* OPENAFS-SA-2018-003
  * Limit unbounded strings in RPCs

OpenAFS 1.8.3pre1
==================

* 1.8.3 Release Candidate announced March 2019
* Support Linux 4.20, 5.0
* Support macOS 10.14 "Mojave"
* Fix vos status missing packet counters regression (13421)
* Fix panic while flushing cache items (13503)
* Fix panic during cache initialization (13307)
* Do not send garbage in the RX userStatus field (13332)

OpenAFS 1.8.3pre1 (continued...)
==================

* Fix bogus cache entries due to a full cache partition, etc. (13443)
* Assorted fixes to avoid segmentation faults (13329 13372)
* Fix volume server crash (13337)
* And more ... see NEWS

Upcoming release OpenAFS 1.6.24
===============================

* To support linux 4.20 and 5.0
* To include same fixes as 1.8.3
* To be released after 1.8.3

master Branch
=============

Changes under code review or already merged:

* gcc 8 warning fixes
* Static analyzer warning fixes
  * Thank you Pat Riehecky
* More conversion to POSIX threads
* Improved Solaris 11.4 VFS integration
* Linux native mount points
* Core RXGK implementation
* And more... see gerrit.openafs.org

> Note:
> Development release series under consideration
> for RXGK snapshots.

RXGK security class
===================

* GSSAPI based security class for RXGK
  * Modern crypto for RX traffic
  * Authentication service framework
* RFC drafts by Simon Wilkinson
  * https://datatracker.ietf.org/doc/html/draft-wilkinson-afs3-rxgk
  * https://datatracker.ietf.org/doc/html/draft-wilkinson-afs3-rxgk-afs

RXGK security class for OpenAFS
===============================

* Phase 1 provides RXGK for intra-dbserver communications
* Developers
  * Ben Kaduk
  * Andrew Deason
* Underlying RFC3961 implementation
  * Simon Wilkinson
* Code for "phase 1" available in Gerrit code review
  * Gerrit topic: 'rxgk-phase1'
  * Most changes merged to master branch

RXGK security class for OpenAFS
===============================

* Core RXGK security class
* OpenAFS code base integration:
  * Build system changes to support RXGK
  * Superuser identification support
  * asetkey and rxdbug changes
  * New pts/vos arguments
  * Error handling changes in OpenAFS
* Initial lab testing and verification
* Phase 1 Limitations:
  * limited to server-to-server, vos/pts to server
  * limited to printed tokens
  * no token negotiation via GSSNegotiate

Get Involved
============

* Review code at gerrit.openafs.org
* Test pre-releases
* Send patches to gerrit.openafs.org
* Discuss on the mail lists:
  * openafs-info@openafs.org
  * openafs-devel@openafs.org

Thanks
======

Thank you, on behalf of the OpenAFS Release Team.
