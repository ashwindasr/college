class_(class_id,class_name,division,st_cnt)
student(st_id,st_fname,st_lname,addr,phone,email,class_id)
teacher(teacher_id,fname,lname,phone,subject)
student_class(st_id,class_id,teacher_id)

CREATE TABLE class(
class_id INT SERIAL PRIMARY KEY,
class_name VARCHAR(15) NOT NULL,
division VARCHAR(15) NOT NULL,
st_cnt SMALLINT NOT NULL
);

CREATE TABLE student(
st_id INT SERIAL NOT NULL PRIMARY KEY,
st_fname VARCHAR(15) NOT NULL,
st_lname VARCHAR(15),
addr VARCHAR(30),
phone INT NOT NULL,
email VARCHAR
