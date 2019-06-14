#!/bin/sh

DESTDIR=${HOME}/texmf/tex/latex

mkdir -p $DESTDIR
for file in *.sty *.png; do
    cp $file $DESTDIR/$file
done
