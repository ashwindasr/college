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
```bashscript
#!/bin/sh

echo $(($1*20 + $2*2 + $3/$4))

```

Question: 12345 seconds  output: 3hrs 25 minutes 45 seconds
```bashscript
#!/bin/sh

x=$1
h=0
m=0
s=0
while [ $x -gt 0 ]
do
	if [ $x -gt 3600 ]	
	then 
		h=$((h+1))
		x=$(($x-3600))
	elif [ $x -gt 60 ]
	then 
		m=$((m+1))
		x=$(($x-60))
	else		
		if [ $x -eq 60 ]
		then
			m=$(($m+1))
		else
			s=$x
		fi
		break
	fi
done	 
echo $h "hours" $m "minutes" $s "seconds"
```

Question: diff: 
sh -v calculate.sh - displays code along with the output
sh -x calculate.sh - displays debugging info along with output

Question: Print all numbers between 50 and 100
```bashscript
#!/bin/sh

x=50
y=100

while [ $x -le $y ]
do
        echo $x
        x=$(($x+1))
done
```

Run a script in the background: &
&& - to 

15/10/18
Learn how to make a make file

22/10/18
* sed command 
	* replace: sed 's/unix/linux/' filename   - replaces all occurences unix with linux within the file
	 	* sed 's/unix/linux/' filename < filename2 -to write to a different file

24/10/18
Question: Get the details of n students and generate mark card with filename as rollno
```script
#!/bin/sh

read -p "Enter number of students: "  n
count=1
while [ $count -le $n ]
do
	echo "Student $count Details:\n"
	read -p "Enter Your Name: "  name
	read -p "Enter Your Roll No: "  roll
	read -p "Enter Mark1: "  mark1
	read -p "Enter Mark2: "  mark2
	read -p "Enter Mark3: "  mark3
	s=$((mark1+mark2+mark3))
	s=$(echo "$s/300" | bc -l)
	s=$(echo "$s*100" | bc -l)
	echo "Name: $name" > "$roll.txt"
	echo "Roll: $roll" >> "$roll.txt"
	echo "Mark1: $mark1" >> "$roll.txt"
	echo "Mark2: $mark2" >> "$roll.txt"
	echo "Mark3: $mark3" >> "$roll.txt"
	echo "Percentage: " $s >> "$roll.txt"
	echo "\n"
	count=$((count+1))
done

```
14/11/18: <br/>
awk:<br />
access column wise: use $n, where n is the number of the column
$0 will print all columns
```bash script
ls -l || awk '{print $1}'
```
also $NR for last column and $(NR-1) for second last ...

