---
title: Creating RPMs
subtitle: Canton Linux Enthusiasts
author: Michael Meffie
date: April 30, 2020
theme: Madrid
---

# Objectives

1. How to build packages for your programs
2. How to modify packages

# A brief history of RPM

* Programs were installed manually for the first 30 years of UNIX:
    * Compiled locally
    * Individual files copied
    * Manual interdependency management
    * No easy way uninstall
* Early Linux distros introduced package management
* RPM developed to fix issues with first generation package managers

# RPM Design Goals

* Ease of use
* Package-oriented focus
* Upgradability of packages
* Package interdependencies
* Query capabilities
* Support for multiple architectures
* **Use of pristine sources**

# Developer vs Packager roles

* Developer
    * upstream project
    * source code
    * versions
* Packager
    * separate release schedule
    * optional code patches
    * package specifications

# Source and Binary RPMs

* Binary RPMs
    * installable
    * one or more rpm files

* Source RPM (SRPM)
    * buildable
    * src.rpm file
    * contains sources and spec
    * systematic way to recreate Binary RPMs

# Packaging workspace

Default workspace is `$HOME/rpmbuild`.

            /home/user/rpmbuild
            +-- BUILD
            +-- BUILDROOT
            +-- RPMS
            +-- SOURCES
            +-- SPECS
            `-- SRPMS

# Spec file structure

        Header Defines    Body Sections
        --------------    -------------
        Name              %description
        Version           %prep
        Release           %build
        Summary           %install
        License           %files
        URL               %changelog
        Source0
        BuildRequires
        BuildArch
        Requires

# Spec file macros

* Confusingly also start with `%`
* System defined values
* Custom defined values
* List with `rpm --showrc`
* Show current value with `rpm --eval "%<name>"`

        $ rpm --eval "%dist"
        .el7

# Building packages

## Building from a spec
* write spec file
* populate `SOURCES`
* run `rpmbuild -ba <spec>`

## Building from a SRPM
* download SRPM file
* run `rpmbuild --rebuild <src.rpm>`

# Building RPMs for Python modules the easy way

## Why build rpms?
* Install your custom modules with `yum` instead of `pip`
* Install precompiled bytecode
* Control your dependencies

## How?
* Create a `setup.py` script as usual
* run `python setup.py bdist_rpm [options]`

# Tutorial

1. Hello World shell script
2. Hello World compiled binary
3. Rebuilding and Patching
4. Setting up a package repository

# Learn More

* Use `mock` for pristine builds
* Read the **RPM Packaging Guide**

        https://rpm-packaging-guide.github.io/

# Questions?

Thank you
