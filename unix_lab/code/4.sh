#Queston: Write a shell script that takes the name of the folder and delte all subfolders of size 0.

#!/bin/sh

for x in $( ls $1 )
do
        if [ -s ./$1/$x ]
        then
                $(rmdir ./$1/$x)
        fi

done
