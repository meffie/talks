.PHONY: all reallyclean

conf=openafs-workshop-2019
talk=robotest
title=$(conf)-$(talk)
theme=SineNomine
images=\
  rf.png \
  workload_tests.png \
  admin_tests.png

all: $(title).pdf

$(title).pdf: $(title).md Makefile $(images)
	pandoc $(title).md -t beamer -V theme:$(theme) -o $(title).pdf

%.png: %.dot
	dot $< -Tpng -o $@

reallyclean:
	rm -f $(title).pdf *.png

show: all
	evince $(title).pdf
