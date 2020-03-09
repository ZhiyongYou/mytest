#!/bin/sh

tels="1 2 3 4 5 6"

dir=`dirname $0`
echo $dir

s_daq=$dir/wfcta_daq.sh

echo $s_daq
#for tel in $tels; do
#   ${s_daq} $tel state 1
#done
