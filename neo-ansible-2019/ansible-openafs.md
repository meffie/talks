---
title: Developing Ansible Roles for OpenAFS
author: Michael Meffie, Sine Nomine Associates
date: August 19, 2019
---

# Intro

* Principal Software Engineer at Sine Nomine Associates
* We do enterprise grade commercial support for OpenAFS
* This talk is about our experiences in going from 0 to 60 with Ansible

# OpenAFS

Elevator pitch

* what if your users never needed to install software?
* what if your developers could deploy new versions globally?
* what if no matter which machine you are on, your files, in the same place.
* single sign-on read and write access
* move data between servers as needed during the day

# OpenAFS

* Distributed, caching, network filesystem
* Clients for solaris, linux, BSDs, macos, windows
* Servers normally run on linux, BSD, linux
* Requires Kerberos for authentication
* Traditionally setup can take a new person days or weeks!

# goals

* easy, fast deployment of OpenAFS servers and clients
* avoid homebrew tools
* initial usage: lab
    * do not preclude production
* multi platform support
    * start with rhel7
    * added debian/ubuntu
    * add more later

# constraints

* limit ansible features
* defer tags
* defer depends
* target ansible versions installed by os





