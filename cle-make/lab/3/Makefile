# Run an Ansible playbook.

PYTHON = /usr/bin/python3.9
VIRTUAL_ENV = .venv
PIP = $(VIRTUAL_ENV)/bin/pip
ACTIVATE = $(VIRTUAL_ENV)/bin/activate
VENV = . $(ACTIVATE);

.PHONY: prod
prod: $(ACTIVATE) lint
	$(VENV) ansible-playbook -i hosts.ini playbook.yml

.PHONY: lint
lint: $(ACTIVATE)
	$(VENV) ansible-lint playbook.yml

$(ACTIVATE): $(PIP) requirements.txt
	$(PIP) install -r requirements.txt
	touch $(ACTIVATE)

$(PIP): .venv
	$(PIP) install -U pip wheel
	touch $(PIP)

$(VIRTUAL_ENV):
	$(PYTHON) -m venv $(VIRTUAL_ENV)
	touch $(VIRTUAL_ENV)
