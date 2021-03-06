#!/bin/bash

# Input
address=$1

video_filename="$(youtube-dl --get-filename -o '%(title)s.%(ext)s' --restrict-filenames $address)"
video_url="$(youtube-dl --get-url $address)"

# modify aria2c options as needed
aria2c -x16 -s20 -k1M --out=$video_filename $video_url