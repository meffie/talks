.PHONY: all clean reallyclean noclean

title=hepix-2019-openafs-rel-team
theme=Madrid

all: $(title).pdf clean

all_noclean: $(title).pdf

$(title).pdf: $(title).md Makefile
	echo "\documentclass[c, ignorenonframetext, xcolor=svgnames]{beamer}"   >  $(title).tex
	echo "\usetheme{$(theme)}"                                               >> $(title).tex
	echo ""                                                                 >> $(title).tex
	snark-beamup $(title).md                                                >> $(title).tex
	# run pdflatex twice for toc
	pdflatex $(title).tex
	pdflatex $(title).tex

reallyclean: clean
	rm -f $(title).pdf

clean:
	rm -f *.aux *.log *.nav *.out *.snm *.tex *.toc *.vrb
