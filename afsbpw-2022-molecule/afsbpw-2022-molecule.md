---
title: OpenAFS development and testing with Ansible Molecule
author: Michael Meffie, Sine Nomine Associates
date: June 15, 2022
abstract:
  - In this talk we demonstrate how to use Ansible Molecule to easily create
    OpenAFS development and testing environments on one or more local or cloud
    hosted virtual machines. Prebuilt OpenAFS packages can be installed or OpenAFS
    can be installed from source to create clients, fileservers, and databases on
    various platforms. A Kerberos realm can also be automatically created for
    development and testing.
  - Molecule provides support for testing with multiple instances, operating
    systems and distributions, virtualization providers, test frameworks and
    testing scenarios.
---

![](images/molecule.png)

Ansible Molecule
----------------


* Ansible is an open source IT automation engine that automates provisioning,
  configuration management

* Molecule is the standard framework for testing Ansible roles and
  playbooks

* Easily spinup local "infrastructures" for testing roles and playbooks

* How can we make it easier for people to get OpenAFS up and running
  by leveraging Ansible and Molecule?

Molecule Scenario
-----------------

* Key concept in molecule

* Defines the number and type of platforms and how to create them

* Defines the Ansible inventory (groups and variables)

* Specifies the Ansible playbook to setup the instances

* Defines the verification method


Scenario configuration
----------------------

* Each scenario consists of a `molecule.yml` file and a set of playbooks

* The `molecule.yml` specifies everything needed to create the infrastructure
  and to verify

* Instances are created/destroyed by driver plugins or by custom playbooks

* Verification is performed by verifier plugins or a custom playbook

Molecule Test Cycle
-------------------

* Create one or more instances (containers or virtual machines)

* Run an Ansible playbook to create an infrastructure

* Verify

* Cleanup and destroy instances

Drivers
-------

![](molecule-drivers.png)

Verification plugins
--------------------

![](molecule-verifiers.png)

Molecule commands
----------------

    test         Run full create/verify/destroy cycle.

    list         List status of instances.
    create       Start the instances.
    converge     Configure instances
    login        Log in to one instance with ssh.
    verify       Run automated tests against instances.
    destroy      Destroy the instances.

See molecule --help for the complete list.


OpenAFS Ansible Collection
--------------------------

A set of Ansible Roles and Modules to deploy OpenAFS.

* MIT Kerberos KDC and workstation Roles

* OpenAFS Client and Server Roles

* OpenAFS Modules (tasks)

* Example Playbooks

* Distributed via github and Ansible Galaxy

* Automatically installed by molecule

OpenAFS Installation Methods
----------------------------

OpenAFS Ansible Collection supports a variety of installation methods.

* Install with package manager

* Upload prebuilt packages

* Checkout source code, build, and install
  - git checkout
  - gerrit checkout
  - source tarball

* Installed versions and methods my vary by instance

Molecule Converge Playbook
--------------------------

* Import OpenAFS Collection

* Install and configure Kerberos, generate keys

* Install and configure OpenAFS clients, db servers, fileservers

* Create and mount top-level volumes

* Create initial users and groups

Robot Framework Verification
----------------------------

On instances in the test group:

* Install Robot Framework

* Install required test libraries

* Download Robot Framework test cases (robot files)

* Run specified test cases

* Download report and logs

Molecule Challenges
-------------------

* Molecule documentation is limited.
  * Offset by lots of online material.

* Duplication of yaml in `molecule.yml` files
  * Base configuration files can help
  * Possible to generate files with templates (e.g. Jinja2)

* Driver/Platforms coupling makes it harder to create reusable scenarios

* login command is currently broken (version 3.6.1)


Getting started
---------------

* Install Vagrant and a virtualization provider (e.g., Virtualbox)

* Install Python3, pip3, virtualenv, cookiecutter

* Create a molecule scenario with cookiecutter

* Install molecule and ansible packages with pip3

* Run molecule

Demo
----

    $ sudo apt-get install python3 python3-venv python3-pip
    $ python3 -m pip install --user cookiecutter
    $ cookiecutter \
        --directory cookiecutter/testcell-scenario \
        https://github.com/openafs-contrib/openafs-robotest
    scenario_name [Untitled]: my-first-scenario
    ...
    $ cd my-first-scenario
    $ python3 -m venv venv
    $ . venv/bin/activate
    (venv) $ pip3 install -r requirements.txt
    (venv) $ molecule test

Acknowledgements
----------------

Many thanks

* Ralf Brunckhorst
* Cheyenne Wills
* Mark Vitale
* Marc Schmitt, aka risson

More Info
---------

Ansible Molecule

  https://molecule.readthedocs.io/en/latest/

OpenAFS Ansible Collection

  https://openafs-ansible-collection.readthedocs.io/en/latest/

OpenAFS RobotTest

  https://openafs-robotest.readthedocs.io/en/latest/index.html

Questions?
----------

Thank you
