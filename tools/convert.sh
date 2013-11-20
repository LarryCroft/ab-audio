#!/bin/sh

# Usage: mp3 in.wav 128
mp3() {
    inPath=$1
    bitrate=$2

    tempMp3Path=${bitrate}.mp3
    outPath=${bitrate}.wav

    lame -q 0 -b ${bitrate} --resample 44.1 ${inPath} ${tempMp3Path}
    lame --decode ${tempMp3Path} ${outPath}

    rm ${tempMp3Path}
}

wav=$1

mp3 $wav 64
mp3 $wav 128
mp3 $wav 320
