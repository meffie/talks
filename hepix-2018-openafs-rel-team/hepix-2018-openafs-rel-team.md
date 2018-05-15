Title: OpenAFS Release Team Report
Author: Michael Meffie
Date: May 15, 2018

OpenAFS Release Team
====================

* Weekly meetings via jabber
  - jabber: release-team@conference.openafs.org
  - email: release-team@openafs.org
* Regular participants
  - Stephan Wiesand - 1.6.x release manager
  - Benjamin Kaduk - 1.8.x release manager
  - Mark Vitale
  - Michael Meffie

Release series
==============

* 1.6.x stable series continues to be maintained
* 1.8.0 was released in April 2018!
  - Six years of development work pulled into a stable release
* Master branch is now open for new features

Release process
===============

* Code reviews held on https://gerrit.openafs.org
* Commits merged to master (development branch)
* Cherry picked from master to stable branches and re-reviewed
* See wiki.openafs.org developers section

OpenAFS code contributors
=========================

Committed within the last 24 months:

    Anders Kaseorg          Ian Wienand
    Andrew Deason           Jeffrey Altman
    Benjamin Kaduk          Joe Gorse
    Caitlyn Marko           Jonathon Weiss
    Chaskiel Grundman       Marcio Barbosa
    Christof Hanke          Mark Vitale
    Damien Diederen         Matt K. Light
    Daria Phoebe Brashear   Michael Lass
    Dave Botsch             Michael Meffie
    Garrett Wollman         (continued...)

OpenAFS code contributors
=========================

    Nathaniel Filardo       Seth Forshee
    Neale Ferguson          Stephan Wiesand
    Pat Riehecky            Tim Creech
    Sergio Gelato           Yadav Yadavendra


OpenAFS 1.6.x stable series
===========================

* 2018-04-17 1.6.22.3
* 2018-02-01 1.6.22.2
* 2017-12-21 1.6.22.1
* 2017-12-05 1.6.22
* 2017-09-21 1.6.21.1
* 2017-07-04 1.6.21
* 2017-04-13 1.6.20.2
* 2016-12-14 1.6.20.1
* 2016-11-30 1.6.20
* 2016-11-10 1.6.19
* 2016-08-03 1.6.18.3
* 2016-07-18 1.6.18.2
* 2016-06-21 1.6.18.1

Stable release priorities
=========================

* Security fixes
* Bug fixes
* Linux mainline kernel releases
* Distro specific kernel releases
* Latent bugs and warnings uncovered by compiler improvements
* Documentation updates
* Minor features and improvements
* Contributed packaging files

Security advisories
===================

* OPENAFS-SA-2017-001
  * Remote triggered rx assertion failure
  * Fixed in 1.6.22 (MTU sanity checks)
* OPENAFS-SA-2016-003
  * Directory information leaks
  * Fixed in 1.6.20 (clear recycled buffers)

Platform support for linux
==========================

* RHEL 7.5 directory handling (1.6.22.3)
* RHEL 7.4 current working directory fixes (1.6.22.2)
* Changes to support mainline linux (4.17rc as of today)
* Nightly build and smoke test of linux rc kernels

Platform support
================

* Solaris 11.3
  - Oracle Developer Studio support
* MacOS
  - High Sierra (10.13) as of 1.6.22.2
  - fixes, packaging, APFS aware

Upcoming 1.6.23 release
=======================

* ubik: update epoch as soon as sync-site is elected
* ubik: fix quorum lose on first write transaction
* Solaris 11.3: fix deadlock while flushing RO vnodes
* avoid counting bad opcode towards abort threshold
* vldb cache timeout option; afsd -volume-ttl
* FBSD sysnames for i386 and amd64 10.4, 11.1, and 12.0
* rpm spec file: separate debuginfo packages for kmods
* refactor acinclude.m4
* support for git review

OpenAFS 1.8.0
=============

What's new in 1.8.0

* Many, many internal code cleanups
* Better support for non-DES encryption types
* Pthreaded vlserver, ptserver, and most utilities
* Rx atomics and other Rx improvements
* Do not truncate server log files on startup
* Remove Linux 2.2 and 2.4 support
* and may more

See NEWS

OpenAFS 1.8.1 upcoming
======================

* Fix for crash when cache-bypass in enabled
* More useful library exports for external tools
* Build fix for broken GNU libtool on Solaris

master branch
=============

* rxgk phase 1 patches under review
* sockaddr conversion
* backlog of changes and fixes to be reviewed


EOF
===

This slide intentionally left blank.
 
