---
title: An OpenAFS Site Report
subtitle: Code Name Sunrise
author:
 - Ralf Brunckhorst
 - Michael Meffie (SNA)
date: June 19, 2019
theme: SineNomine
---

# History of AFS at Sunrise

1999

:    AFS was introduced at one site in Sweden.

2000s

:    More sites were added.

2006

:    AFS read-only sites limit reached. Four **subcells** were created.

2015

:    CellCC deployed to support multi-cell sync.

2019

:    DPF deployed for volume releases over WAN.

# Business View of the AFS Service

* Series of Linux/Unix based services which are vital to development and test
  at several sites on three continents.

* These services include Linux and Unix managed workplaces, Terminal Servers,
  Global Application delivery and other services which are dependent on AFS.

* The AFS file system provides a transparent mechanism to supply the
  application tree, environment files, Application Release Center (ARC) project
  environments and toolboxes to Linux/Unix services such as managed workplaces
  around the world.

> Many people are not aware of the AFS service since it is transparent.

# Managed Workplaces

Two major areas of AFS seen from Managed Workplace clients at
Sunrise.

* Applications
* Environment

# Application Release Center (ARC)

The Application Release Center (ARC) is a project to get a common, highly
flexible and configurable UNIX environment.

# Applications namespace

Application distribution for Solaris, RedHat, SuSE, Ubuntu.

Application symlink to AFS:

    /app -> /afs/${cell}/app/

# Environment namespace

The Environment namespace contains several important types of files used by
Sunrise:

* Site files
* Licences
* Application Release Center (ARC) files

Environment symlink to AFS:

    /env -> /afs/${CELL}/env/

# CellCC

Scaling issues:

- Still one Cell with only 3 AFSDB-servers worldwide
- Change of mount points required in TAG-volumes (via dumpscan)
- Double storage capacity needed on TAG RW-servers

SNA was engaged in 2015 to create a product to support multi-sync for different
Cells.

**CellCC** is now used to sync a single source-cell to four other cells on
three continents.

# DPF

At Sunrise we have seen performance problems with AFS releases (UDP-based) when
it comes to WAN traffic.

Therefore we have implement a new mechanism developed by SNA: DPF for releases
(TCP-based) This is now active since several months as default for releases.

**Improvement factor: 5 - 15 times faster depending on network topology**

# Statistics

* 5 active AFS cells
    * 1 source cell
    * 4 target cells
* 33 AFS servers

# Servers

OpenAFS fileservers.

Model                   Number
----------------------  ------
ProLiant DL360 Gen9         12
ProLiant DL360p Gen8         6

Database servers are deployed on virtual machines.

Model                     Number
-----------------------   ------
XEN                            1
VMware Virtual Platform       14

# AFS-server OS usage overview

Vendor Version ARCH     Number
------ ------- -------- ------
RedHat 6       `x86_64`      2
RedHat 7       `x86_64`     31

# AFS Clients

Cell       Number
---------  ------
sero.gic    13070
seli.gic     9997
cn.ao         384
mo.ca.am      178
            23629

# Clients by OS

Number of scanned systems grouped by OS:

Name         Number
---------    ------
RedHat        15596
SLE            7811
Ubuntu          654
Solaris         319
openSuse          7
Debian            1

# Client arch

OSS       Ver  Arch     Number
--------  --- -------   ------
RedHat    6   `x86_64`  7952
RedHat    7   `x86_64`  7559
SLE       11  `x86_64`  4725
SLE       12  `x86_64`  2961
Ubuntu    16  `x86_64`  553
Solaris   10  `sparcv9` 266
Ubuntu    18  `x86_64`  78
SLE       11  `i686`    67
RedHat    5   `x86_64`  62
Solaris   11  `sparcv9` 42
SLE       10  `x86_64`  29
SLE       10  `i686`    29


# Client arch

OSS       Ver  Arch     Number
--------  --- -------   ------
Ubuntu    14  `x86_64`  22
RedHat    5   `i686`    17
openSuse  11  `i686`    7
RedHat    6   `i686`    4
Solaris   10  `amd64`   4
Solaris   11  `amd64`   3
Solaris   9   `sparcv9` 2
Solaris   8   `sparcv9` 2
RedHat    4   `i686`    1
Ubuntu    12  `x86_64`  1
RedHat    4   `x86_64`  1
Debian    0   `x86_64`  1

# AFS 1.6 Clients

AFS      Vers       Number
-------  ------     -----
OpenAFS  1.6.21     12252
OpenAFS  1.6.22     4450
OpenAFS  1.6.20     3118
OpenAFS  1.6.23     1975
OpenAFS  1.6.9      957
OpenAFS  1.6.10     322
OpenAFS  1.6.5      210
OpenAFS  1.6.x      872
OpenAFS  1.4.x      112

# AFS 1.8 Clients

**Migration to 1.8.x underway.**

AFS      Vers       Number
-------  ------     -----
OpenAFS  1.8.2      46
OpenAFS  1.8.0pre5  34
OpenAFS  1.8.3      4
OpenAFS  1.8.3pre1  1

# Disk cache vs Mem cache

Cache      Number of clients
---------  -----------------
disk                  24262
memory                   89

# Volume releases

![monthly-releases](monthly-releases.pdf){width=80%}

# Thank you

Questions?
