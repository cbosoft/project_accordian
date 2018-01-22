clean:
	rm -rf *.log *.aux *.toc *~ *.pdf
docs:
	pdflatex desdoc.tex
	pdflatex desdoc.tex
	rm -rf *.log *.aux *.toc *~
