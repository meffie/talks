Name:           hello
Version:        2.0
Release:        2%{?dist}
Summary:        Hello world packaging example.

License:        GPLv3+
URL:            https://example.com/hello
Source0:        https://example.com/hello/hello-2.0.tar.gz
Patch0:         mychange.patch

BuildRequires:  make
BuildRequires:  gcc

%description
A hello world RPM package.

%prep
%setup
%patch0

%build
./configure
make

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT

%files
/usr/bin/hello
%license LICENSE

%changelog
* Thu Apr 30 2020 Ty Cobb <tycobb@yoyodyne.com> - 2.0-1
- Binary release
* Thu Apr 30 2020 Ty Cobb <tycobb@yoyodyne.com> - 1.0-1
- Initial release
