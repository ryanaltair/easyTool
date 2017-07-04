#!/bin/bash
#convert svg to png using librsvg with black background
#write by ryanaltair
#cd somewhere
for image in *.svg;do
	rsvg-convert "$image" -b black -o "${image%.svg}.png"
    rm $image
#echo "image $image converted to ${image%.svg}.png "
done 

