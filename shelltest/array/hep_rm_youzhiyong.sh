#!/bin/bash
Bin=/afs/ihep.ac.cn/soft/common/sysgroup/hep_job/bin
for i in `$Bin/hep_q -u hzhou`
do
echo $i
#  m=${i[0]%.*}
#  m=${m%.*}
#  if [ $m -lt 3270633 -a $m -gt 3270055 ];then
#    echo $m
#echo $m
#echo ${i[1]}
#/afs/ihep.ac.cn/soft/common/sysgroup/hep_job/bin/hep_rm ${m}.0
#  fi
#  /afs/ihep.ac.cn/soft/common/sysgroup/hep_job/bin/hep_rm -p virtual $m 
done
