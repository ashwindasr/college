*4/10/18*

Question :-  print the name of all users with matching group id

```shellscript
       cat /etc/passwd | grep "<id name>" | cut -d: -f1         
```

*5/10/18*
 
Question: Add unspecified number of command line arguments(numbers).
``` shellscript 
#!/bin/sh
s=0
for x in $*
do
        s=`expr  $x + $s `
done
echo $s
```

Question: sum of numbers greater than 5 [-gt]

```shellscript
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
```
Question: Eliminate duplicate names <br/>
When ordering is not important:
```bashscript
sort -u filename
```
To preserve ordering:
```bashscript
awk '!a[$0]++` filename 
```
```bashscript

#!/bin/sh

for i in $(awk '!a[$0]++' $1)
do 
        echo $i 
done
```
Queston: Write a shell script that takes the name of the folder and delte all subfolders of size 0.
```bashscript
#!/bin/sh

for x in $( ls $1 )
do
        if [ -s ./$1/$x ]
        then
                $(rmdir ./$1/$x)
        fi

done
```
Question: Takes a folder name and produces a file that has the names of subfolders of size 0.
```bashscript
#!/bin/sh

for x in $( ls $1 )
do
        if [ -s ./$1/$x ]
        then
                echo $x >> file1.txt 
        fi

done
```
Question: Takes the file where each line is given in the format, make a folder for each user name and give read write access for user only.
```bashscript
#!/bin/sh

for x in $(cat $1 | cut -d ' ' -f2)
do 
        mkdir $x
        chmod 600 $x
done
```
11/10/18
Question: Rename a file with the owner appended to filename
```bashscript
#!/bin/sh

if [ $1 ] 
then

        mv $1 "$1_$( ls -l "$1" | cut -d ' ' -f3)"

fi 
```
Question: Rename all the files with owner name
```bashscript
#!/bin/sh

for x in $( ls )
do
	mv $x "${x}_$( ls -l $x | cut -d' ' -f3)"
done
```
12/10/18
Question: ax20 - bx2 + c/d 
1 12 5 2 ans: 18

Question: 12345 seconds  output: 3hrs 25 minutes 45 seconds

Question: diff: 
sh -v calculate.sh
sh -x calculate.sh

Question: Print all numbers between 50 and 100

Run a script in the background: &
&& - to 
