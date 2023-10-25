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

# What's a Kernel?

* Makes it possible for your programs to run on different systems, now, and in the future
* Manages access to hardware (drivers)
* Manages memory
* Process scheduling, progress and group isolation
* Handles hardware interrupts
* Provides syscall interface for programs
* etc

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

# Demo Module

Demo module for illustration

* Generate random passwords using the kernel
* Basic char device driver (/dev/password)
* Show how to use ioctl and sysctl to set password length

# Demo Module: Part 1

* Makefile using kbuild
* Load and unload module

# Demo Module: Part 2

* Register a char device major number
* Register a device class
* Auto-create the /dev/password file
* Auto-setup /dev/password file permissions

# Demo Module: Part 3

* Initial file operation functions
* Send "hello world" from the kernel to userspace

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

