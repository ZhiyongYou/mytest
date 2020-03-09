#!/bin/bash
xpos=250.1213213
x=1
while [ $x -le 10 ]
do
  echo $xpos
  xpos=`echo "$xpos + 5.7"|bc`
  x=`expr $x + 1`
done
