---
title: Building KVM virtual machines quickly with virt-builder and cloud-init
subtitle: Akron Linux Users Group
author: Michael Meffie
date: January 6, 2021
theme: Madrid
---

# Objectives

Show how to quickly create local kvm guests with pre-built images.

* vagrant
* cloud-init
* virt-builder

# Hardware Virtualization Support

* Processor support required and must be enabled.
* See `/proc/cpuinfo`
* Intel: `vmx` flag
* AMD: `svm` flag
* Also, be sure virtualization is enabled in BIOS!

Example:

    $ grep vmx /proc/cpuinfo

# KVM Software Stack

![](kvm1.eps)

* virt-manager, virt-install - user interface
* libvirt - virtual machine management
* qemu - machine emulation (guest)
* guestfs - virtual machine image tools
* kvm - kernel module for virtualization

# Libvirtd

![](libvirtd.eps)

# Vagrant

* HashCorp tool for spinning up guests.
* Supports a variety of providers
* Linux provider is experimental, but works
* Search for libvirt provider boxes
* Do not install vagrant with apt or yum!
* Ruby based

# cloud-init

![](cloud-init.eps)

# cloud-init

* Widely used for depoying images on cloud providers
* Many images available online
* Boots quickly
* No root passwords in cloud-init images
* Data is injected on first boot using link-local addresses
* NoCloud option available for regulare libvirt/kvm setup

# cloud-init

* Download a cloud-init enabled image
* Create a virtual cdrom disk with the cloud-init meta-data
* Create a guest with the disk attached
* cloud-init will use the data from attached disk
* See kvm-install-vm shell script

# cloud-init

    $ cat meta-data
    instance-id: iid-local01;
    local-hostname: cloudimg;

    $ cat user-data
    #cloud-config
    password: passw0rd
    chpasswd: { expire: False }
    ssh_pwauth: True

    $ genisoimage -output seed.iso
                  -volid cidata
                  -joliet
                  -rock user-data meta-data

# virt-builder

* libguestfs tool suite
* virt-builder - download and customize image
* virt-sysprep - edit images clones
* virt-up - homebrew virt-builder/virt-sysprep wrapper

# virt-builder

![](libguestfs.eps)

# Demos

* kvm-install-vm
* virt-up
