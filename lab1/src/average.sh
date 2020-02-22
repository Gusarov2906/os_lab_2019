#!/bin/sh
n=$#
averange=0
for (( i=1; i <= n; i++ ))
do
averange=$[ $averange + ${i} ]
done
averange=$[ $averange / $n ]
echo $n
echo $averange