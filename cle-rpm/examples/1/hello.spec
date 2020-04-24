Name:           hello
Version:        1.0
Release:        1%{?dist}
Summary:        Hello world packaging example.

License:        GPLv3+
URL:            https://example.com/hello
Source0:        https://example.com/hello/hello-1.0.sh

Requires:       bash
BuildArch:      noarch

%description
A hello world RPM package.

%prep
cp %{SOURCE0} hello.sh

%build
# Nothing to build in this example.

%install
mkdir -p %{buildroot}/usr/bin/
install -m 755 hello.sh %{buildroot}/usr/bin/hello

%files
/usr/bin/hello

%changelog
* Thu Apr 30 2020 Ty Cobb <tycobb@yoyodyne.com> - 1.0-1
- Initial release
