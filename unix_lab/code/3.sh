# Question: sum of numbers greater than 5 [-gt]

#!/bin/sh
s=0
for x in $*
do
        if [ $x -gt 5 ]
        then
                s=`expr  $x + $s `
        fi
done
echo $s
