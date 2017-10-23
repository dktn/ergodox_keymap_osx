#!/bin/bash -x

cd ../..
where=$1
skip=$2
if [ -z "$where" ]; then
    where="colmxDefault"
fi
output_dir=~/Dropbox/share/ergo/Teensy/$where
hex_path=../../ergodox_ez_dktn_osx.hex
mkdir -p $output_dir
if [ "$skip" == "skip" ]; then
    make dktn_osx && cp $hex_path $output_dir
else
    make dktn_osx && cp $hex_path $output_dir && teensy_loader_cli --mcu=atmega32u4 -w $hex_path
fi
cd keymaps/dktn_osx
