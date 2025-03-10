LATEXCMD = pdflatex -shell-escape -output-directory build/
export TEXINPUTS=.:content/tex/:
export max_print_line = 1048576

mkdir -p build/
pdflatex -shell-escape -output-directory build/ content/kactl.tex
cp build/kactl.pdf .
