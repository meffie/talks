# Run an Ansible playbook.

PYTHON = /usr/bin/python3.9
VIRTUAL_ENV = .venv
PIP = $(VIRTUAL_ENV)/bin/pip
ACTIVATE = $(VIRTUAL_ENV)/bin/activate
VENV = . $(ACTIVATE);

Q = @

.PHONY: prod
prod: $(ACTIVATE) collections
	$(Q)echo "creating production environment."
	$(Q)$(VENV) ansible-playbook -i hosts.ini playbook.yml

collections: $(ACTIVATE)
	mkdir -p collections
	$(VENV) ansible-galaxy collection install foo -p collections
	touch collections

.PHONY: lint
lint: $(ACTIVATE)
	$(VENV) ansible-lint playbook.yml

.PHONY: test
test: lint $(ACTIVATE)
	$(VENV) molecule test

$(ACTIVATE): $(PIP) requirements.txt
	$(PIP) install -r requirements.txt
	touch $(ACTIVATE)

$(PIP): .venv
	$(PIP) install -U pip wheel
	touch $(PIP)

$(VIRTUAL_ENV):
	$(PYTHON) -m venv $(VIRTUAL_ENV)
	touch $(VIRTUAL_ENV)
