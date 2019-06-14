.PHONY: all reallyclean

conf=openafs-workshop-2019
talk=rel-team
title=$(conf)-$(talk)
theme=Madrid

all: $(title).pdf

$(title).pdf: $(title).md
	pandoc $(title).md -t beamer -V theme:$(theme) -o $(title).pdf

reallyclean:
	rm -f $(title).pdf

show: all
	evince $(title).pdf
