#!bin/bash
#using parallel to convert svg to png
#write by ryanaltair
#cd somewhere
parallel rsvg-convert '{}' -o '{.}.png' ::: *.svg

