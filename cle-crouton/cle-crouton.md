Title: Running Linux on a Chromebook with Crouton
Author: Michael Meffie
Date: June 29, 2017

Why Chromebooks
===============

* inexpensive
* light and solid
* 12hr battery life
* no moving parts
* fast to boot and wake
* ships with linux kernel and drivers

Chromebook limitations
======================

* cpu and storage commensurate with price
* chromeos is online only
* javascript-y apps only
* not even a good terminal
* just needs a regular userspace to be useful

Crouton
=======

* Chromium OS Universal Chroot Environment
* run linux programs in a chroot
* instead of dual booting
* x or cli
* install ubuntu based light weight distro with a single command
* runs side-by-side with chromeos
* multiple chroots possible

Linux in 3 easy steps
=====================

1. Enable developer mode
2. Download and then run *crouton* to install linux
3. Start with *startxfce4*


Demo
====

1. Control-D on power up to enter developer mode.
2. Download crouton in chrome: https://goo.gl/fd3zc
3. Control-Alt-t in chrome to enter the crosh shell
4. Run *shell* in crosh
5. To see available targets: sh ~/Download/crouton -t help
6. To install: sudo sh ~/Downloads/crouton -t xfce
7. Example: sudo startxfce4 -n xenial
8. Control-Alt-Shift-F1/F2 to switch

EOF
===

This page intentionally left blank.

