#!/bin/bash
   # exec 0<numbers.txt
    i=0
    s=0
    while read line
    do 
      echo "Arg num №$i : $line" 
      let "s+=line"
      let "i+=1"
    done
    echo "Count : $i"
    let "s=s/i"
    echo "Average : $s"
exit 0