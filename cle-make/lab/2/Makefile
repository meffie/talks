# Run an Ansible playbook.

PYTHON = /usr/bin/python3.9
VIRTUAL_ENV = .venv
PIP = $(VIRTUAL_ENV)/bin/pip
ACTIVATE = $(VIRTUAL_ENV)/bin/activate
VENV = . $(ACTIVATE);

.PHONY: prod
prod: $(ACTIVATE)
	$(VENV) ansible-playbook -i hosts.ini playbook.yml

$(ACTIVATE): $(PIP)
	$(PIP) install ansible==6.7.0
	touch $(ACTIVATE)

$(PIP): $(VIRTUAL_ENV)
	$(PIP) install -U pip wheel
	touch $(PIP)

$(VIRTUAL_ENV):
	$(PYTHON) -m venv $(VIRTUAL_ENV)
	touch $(VIRTUAL_ENV)
