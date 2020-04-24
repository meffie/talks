.PHONY: all reallyclean show

title=cle-rpm

all: $(title).pdf

$(title).pdf: $(title).md
	pandoc $(title).md -t beamer -o $(title).pdf

reallyclean:
	rm -f $(title).pdf

show: all
	evince $(title).pdf
