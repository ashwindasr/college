#Question: Add unspecified number of command line arguments(numbers)

#!/bin/sh
s=0
for x in $*
do
        s=$(($x+$s))
done
echo $s
