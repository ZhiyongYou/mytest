#!/bin/bash
INDIR=/scratchfs/ybj/zhangwm/G4Wcda/muonback/out1root2
for i in `seq 1 99`
do
  file=`ls ${INDIR}/filenum${i}_*.root`
  ii=`printf %03d $i`
  echo $file>>test.txt
done
