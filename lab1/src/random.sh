#!/bin/bash
MAXCOUNT=150
for c in {1..$MAXCOUNT}
#for ((i=0; i<$MAXCOUNT; i++))
do
#    echo "$RANDOM " >> numbers.txt
echo $(od -A n -t d -N 1 < /dev/random) >> numbers.txt
done