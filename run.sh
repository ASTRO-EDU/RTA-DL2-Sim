#!/bin/sh
module load agile-B24-r5
export PFILES=$PWD/conf

make clean
make
