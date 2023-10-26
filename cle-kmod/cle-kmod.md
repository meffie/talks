---
title: Building a Linux Kernel Module
subtitle: Canton Linux Enthusiasts
author: Michael Meffie
date: October 26, 2023
theme: Madrid
---

# About me

* Michael Meffie
* Software Engineer, Sine Nomine Associates
* Slides and code: https://github.com/meffie/talks/cle-kmod

# About this talk

* Let's actually talk about Linux at a Linux Meetup!
* Intro to kernel modules
* Demo code

# Info

* Linux Kernel Module Programming Guide
* Linux documentation and source code

# What's a Kernel?

* Manages access to hardware (drivers)
* Manages memory
* Filesystems
* Process scheduling
* Process (and cgroup) isolation
* Handles hardware interrupts
* Provides syscall interface for programs

# What's a Kernel Module?

* Load and unload a chunk of code in a running kernel
* Modules run in kernel space (not userspace)
* Modules have full access to kernel functions
* Modules make it possible to have smaller pre-built kernel images

# What's a device driver?

* A chunk of code that deals with a particular hardware device
* char drivers, block drivers, bus drivers, network drivers, etc

# Loading Modules

* To see loaded modules: 'lsmod' or '/proc/modules'
* To load a module: 'sudo insmod name.ko'
* To unload a module: 'sudo rmmod name'
* Smart module loader: 'modprobe'

# Module code

* In-tree: Maintained as part of Linux (GPL)
* Out-of-tree: Maintained outside of Linux (Project specific license)
* Linux internals change with every release

# Getting started

Debian

    $ sudo apt update
    $ sudo apt upgrade
    $ sudo reboot
    $ sudo apt install kmod linux-headers-$(uname -r)

Fedora

    $ sudo dnf update
    $ sudo reboot
    $ sudo dnf install kernel-devel kernel-headers

# Demo Module

Demo module for illustration:

* Generate random passwords using the kernel
* Basic char device driver (/dev/password)
* Show how to use ioctl and sysctl to set password length
* Requires Linux 6.1 to 6.4

# Demo Module: Part 1

* Makefile using kbuild
* Load and unload module

# Demo Module: Part 2

* Register a char device major number
* Register a device class
* Auto-create the /dev/password file

# Demo Module: Part 3

* Initial file operation functions
* Send "hello world" from the kernel to userspace
* Auto-setup /dev/password file permissions

# Demo Module: Part 4

* Use the kernel API to generate random password strings

# Demo Module: Part 5

* Add an ioctl to set and get the generated length
* Write a sample python script to use the ioctl

# Demo Module: Part 6

* Add a sysctl parameter to set and get the generated length

# Thanks

Questions?


* Use the kernel API to create an random password string

