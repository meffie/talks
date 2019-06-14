.PHONY: all reallyclean

conf=openafs-workshop-2019
talk=sunrise-site-report
title=$(conf)-$(talk)

all: $(title).pdf

$(title).pdf: $(title).md Makefile monthly-releases.pdf
	pandoc $(title).md -t beamer -o $(title).pdf

monthly-releases.pdf: monthly-releases.dat
	gnuplot monthly-releases.plot

reallyclean:
	rm -f $(title).pdf

show: all
	evince $(title).pdf
