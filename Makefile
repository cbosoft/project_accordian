clean:
	rm -rf *.log *.aux *.toc *~ *.pdf
all:
	pdflatex desdoc.tex
	pdflatex desdoc.tex
	rm -rf *.log *.aux *.toc *~
