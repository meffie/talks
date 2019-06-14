#!/usr/bin/gnuplot

infile="cellcc-dumps.dat"
outfile="cellcc-dumps.pdf"

reset
set term pdfcairo font "Arial,9" noenhanced rounded fontscale 0.5

set output outfile

set style line 80 lt rgb "#808080"
set border 11 back linestyle 80
set style line 81 lt 0
set style line 81 lt rgb "#808080"
set grid back linestyle 81 ytics 

set xdata time
set timefmt "%j"
#set xrange ["2016-08-30":"2019-06-31"]

set xtics nomirror
set ytics nomirror
set y2tics

set autoscale y
set autoscale y2

set y2label "GB"

do for [i=1:2] {
    set style line i lw 2 ps 0.5
}

plot infile using 1:2 with linespoints linestyle 1 title "# of Releases" axes x1y1, \
     ""        using 1:3 with linespoints linestyle 2 title "CellCC" axes x1y2
