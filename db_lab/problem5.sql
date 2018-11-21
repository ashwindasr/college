create table employee(
emp_id serial not null,
name varchar(15) not null,
dob date not null,
sal money not null,
dept_id int not null references department(dept_id)
);

create table department(
dept_id serial primary key,
dept_name varchar(15) not null
);

insert into department(dept_name) values('HR'),('IT'),('Program');

insert into employee(name,dob,sal,dept_id) values('sukumaran','01-01-1998',10000,1),('abhilash','01-01-1998',100000,2),
('nidhi','08-17-1998',200000,2),('varsha','12-15-1998',10000000,1);

update employee set sal=sal+sal*20/100 where dept_id=1;

select max(sal) from employee group by dept_id having dept_id=2;
