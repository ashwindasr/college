/*
BANKDATABASE
branch(b_id,bname,city)
customer(c_id,cname,city)
deposit(acc_no,c_id,b_id,amount,date)
borrow(loan_no,c_id,b_id,amount,date)
*/


create table branch(
b_id serial primary key,
bname text not null,
city text not null
);

create table customer(
cid serial primary key,
cname text not null, 
city text not null
);

create table deposit(
acc_no serial primary key,
cid int not null references customer(cid),
b_id int not null references branch(b_id),
amount numeric not null,
date date not null
);

create table borrow(
loan_no serial primary key,
cid int not null references customer(cid),
b_id int not null references branch(b_id),
amount money not null,
date date not null
);

insert into branch(bname,city) values ('Manacaud','Trivandrum'),('East Fort','Trivandrum'),('Pala','Kottayam');

insert into customer(cname,city) values ('Das','Trivandrum'),('Titus','Kottayam');

insert into deposit(cid,b_id,amount,date) values (1,1,10000,'09-01-2018'),(2,1,20000,'09-01-2018'),(1,2,10000,'09-05-2018');

insert into borrow(cid,b_id,amount,date) values (1,1,10000,'09-01-2018'),(2,1,20000,'09-01-2018'),(1,2,10000,'09-05-2018');

/*Find the number of customers who have loan in each branch */
select * from customer natural join borrow;
/*List all details of all customers*/
select * from customer;
