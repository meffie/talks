Title: AFSmin
Date: March 28, 2014

Scout
=====

![scout](scout.png)

(1987 called, they want their program back.)

AFSmin
======

![afsmin](afsmin.png)


AFSmin goals
============

* A better scout/afsmonitor for OpenAFS
* To be distributed as an OpenAFS contrib project
  - foster the OpenAFS contrib ecosystem
  - open source license (2 clause BSD)
  * https://github.com/openafs-contrib
* Batteries included, no assembly required
  * Easy to deploy and start using
  * Zero config
* Useful
  * Modern UI
  * REST API for scripting and integration

How are things going?
=====================

> What are the sort of things that would be useful to know.

* Load and performance
  - How are the servers doing?
  - What are my busiest servers?
  - What are my busiest volumes?
  - What are the most active clients?
  - Is the load balanced?

* Space and Quotas
  - By server, partition, volume, user?
  - Is the space balanced?

Looking for trouble
===================

* Server troubles
* Volume troubles
  - volumes offline
  - stray locks
  - stray volumes
* Release troubles
  - are there failed releases
  - what are the releases in progress; ETA?


afsmin-server
=============

In Progress: afsmin-server

* Single, multi-threaded, server process
* Can be run out of the bosserver
* Runs as a non-root user
* Embedded http/https server for UI
* REST api with JSON for scripting and integration
* No "screen scraping" of OpenAFS commands; call RPCs directly
* Future: lua scripting for plugins

afsmin-server components
========================

* civetweb (formerly mongoose) - embedded http support
* Clear Silver - html templating
* libopenssl - https
* librrd - round robin db and graphs
* libsqlite - embedded db
* libkrb5 - kerberos libs
* jannson - JSON
* OpenAFS libs

afsmin-agent
============

Future: afsmin-agent

* Per fs/db daemon process
* Watch the OpenAFS fs audit logs
* Collect, aggregate data for afsmin-server

Summary
=======

* AFSmin is a work-in-progress OpenAFS contrib project for site administrators
* Sorry no timelines; but testing at one largish OpenAFS site to begin soon


Thanks
======

![andy](andy.jpg)
