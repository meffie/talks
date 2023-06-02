.PHONY: all reallyclean

conf=afsbpw-2023
talk=dv
title=$(conf)-$(talk)
theme=SineNomine
images=

all: $(title).pdf

$(title).pdf: $(title).md Makefile $(images)
	pandoc $(title).md -t beamer -V theme:$(theme) -o $(title).pdf

%.png: %.dot
	dot $< -Tpng -o $@

reallyclean:
	rm -f $(title).pdf *.png

show: all
	evince $(title).pdf &
