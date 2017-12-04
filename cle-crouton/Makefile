.PHONY: all clean reallyclean noclean diagrams

title=cle-crouton
theme=Madrid


DIAGRAMS := $(patsubst %.dot,images/%.png,$(wildcard *.dot))

all: $(title).pdf clean

all_noclean: $(title).pdf

$(title).pdf: $(DIAGRAMS) $(title).md Makefile
	echo "\documentclass[c, ignorenonframetext, xcolor=svgnames]{beamer}"   >  $(title).tex
	echo "\usetheme{$(theme)}"                                              >> $(title).tex
	echo "\usepackage{upquote}"                                             >> $(title).tex
	echo "\setbeamersize{text margin left=3em,text margin right=1em}"       >> $(title).tex
	echo ""                                                                 >> $(title).tex
	snark-beamup $(title).md                                                >> $(title).tex
	# run pdflatex twice for toc
	pdflatex $(title).tex #>/dev/null
	pdflatex $(title).tex #>/dev/null

images/%.png: %.dot
	mkdir -p images
	dot -Tpng -o$@ $<

reallyclean: clean
	@rm -f $(title).pdf

clean:
	@rm -f *.aux *.log *.nav *.out *.snm *.tex *.toc *.vrb *.bak

show: $(title).pdf
	evince $(title).pdf
