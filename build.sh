#!/bin/bash -x

qmkpath=../../../..
buildpath=.build/ergodox_ez_dktn.hex
cd $qmkpath
where=$1
skip=$2
if [ -z "$where" ]; then
    where="colmxDefault"
fi
output_dir=~/Dropbox/share/ergo/Teensy/$where
mkdir -p $output_dir
if [ "$skip" == "skip" ]; then
    make ergodox_ez:dktn && cp $buildpath $output_dir
else
    make ergodox_ez:dktn:teensy && cp $buildpath $output_dir
fi
cd keyboards/ergodox_ez/keymaps/dktn
