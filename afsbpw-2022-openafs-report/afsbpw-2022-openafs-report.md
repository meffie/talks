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

TODO
----

* put a report here

OpenAFS Buildbot
----------------

* buildbot.openafs.org is hosted by MIT
  - Performs test builds of each gerrit submission

* Upgraded to Buildbot 3.5.0 in 2022
  - Configuration is Ansible managed now.
  - New builder names to distinguish gerrit triggered from nightlies

* New contributed builders in 2022
  - OpenSUSE 15
  - FreeBSD 12
  - Debian 11
  - Fedora 35
