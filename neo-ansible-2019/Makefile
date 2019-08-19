.PHONY: all reallyclean

title=ansible-openafs
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
	evince $(title).pdf
