Setting up a yum repo.

Prereqs:

    $ sudo yum install creatrepo

Install a webserver:

    $ sudo yum install httpd
    $ sudo systemctl enable httpd
    $ sudo systemctl start httpd

Populate with packages:

    $ cd ~/rpmbuild/RPMS
    $ sudo cp -r -v * /var/www/html

Create the repo:

    $ sudo createrepo /var/www/html

    $ sudo cp example.repo /var/www/html

    $ cat /var/www/html/example.repo
    [example]
    name=Example repo
    baseurl=http://dr01.example.com/
    enabled=1
    gpgcheck=0

On each machine, add the repo:

    $ sudo yum-config-manager --add-repo http://dr01.example.com/example.repo

Now we can install our packages with yum:

    $ sudo yum install hello

(Every time rpm are added, run `sudo createrepo /var/www/html`)
(Clear cached repo data on clients with `sudo yum clean all`)
