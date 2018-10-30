# Question :- print the name of all users with matching group id

cat /etc/passwd | grep $1 | cut -d: -f1         

