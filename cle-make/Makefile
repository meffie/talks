.PHONY: all reallyclean preview show

title = cle-make
transition = PagePeel
images = hello.pdf rule.pdf

all: $(title).pdf

$(title).pdf: $(title).md $(images)
	pandoc $(title).md -t beamer -o $(title).pdf

reallyclean:
	rm -f $(title).pdf hello.pdf

preview: all
	evince $(title).pdf

show: all
	#impressive --transition $(transition) $(title).pdf
	evince $(title).pdf

hello.pdf: hello.dot
	dot -Tpdf hello.dot -o hello.pdf
