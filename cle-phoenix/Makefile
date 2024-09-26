.PHONY: all reallyclean preview show

title=cle-phoenix
transition=PagePeel

all: $(title).pdf

$(title).pdf: $(title).md
	pandoc $(title).md -t beamer -o $(title).pdf

reallyclean:
	rm -f $(title).pdf

preview: all
	evince $(title).pdf

show: all
	#impressive --transition $(transition) $(title).pdf
	evince $(title).pdf
