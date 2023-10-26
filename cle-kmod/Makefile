.PHONY: all reallyclean preview show

title := cle-kmod
enscript := enscript --fancy-header --color --margins=72:31:31:31
sources := demo/Makefile $(wildcard demo/*.c) $(wildcard demo/*.py)

all: $(title).pdf $(title)-notes.pdf

$(title).pdf: $(title).md Makefile
	pandoc $(title).md -t beamer -o $(title).pdf

$(title)-notes.pdf: $(title).md $(sources) Makefile
	$(enscript) -o tmp1.ps $(title).md
	$(enscript) -o tmp2.ps --highlight $(sources)
	psmerge -otmp.ps tmp1.ps tmp2.ps
	ps2pdf tmp.ps $(title)-notes.pdf
	rm tmp*.ps

clean reallyclean:
	rm -f $(title).pdf $(title)-notes.pdf *.ps

preview show: $(title).pdf
	evince $(title).pdf

notes: $(title)-notes.pdf
	evince $(title)-notes.pdf
