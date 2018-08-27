#include <iostream>
#include <string.h>
using namespace std;

class Student
{
	protected:
		string name;
		int rollno;
	public:
		void getdetails1();
		void disp1();
};
void Student::disp1()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Roll no: "<<rollno<<endl;
}
void Student::getdetails1()
{
	cout<<"Enter name: ";
	getline(cin,name);
	cout<<"Enter roll no: ";
	cin>>rollno;
}
class Sports
{
	protected:
		float sportsmarks;
	public:
		void getdetails2();
		void disp2();	
};
void Sports::getdetails2()
{
	cout<<"Enter sports marks: ";
	cin>>sportsmarks;
}
void Sports::disp2()
{
	cout<<"Sports marks: "<<sportsmarks<<endl;
}
class Statement:public Student, public Sports
{
	private:
		float mark1,mark2,mark3;
	public:
		void getdetails();
		void dispfinal();	
};
void Statement::getdetails()
{
	cout<<"Enter marks: \n";
	cout<<"Mark 1: ";
	cin>> mark1;
	cout<<"Mark 2: ";
	cin>> mark2;
	cout<<"Mark 3: ";
	cin>> mark3;
}
void Statement::dispfinal()
{
	cout<<"Total marks: "<< (mark1+mark2+mark3+sportsmarks)<<endl;
}
int main()
{
	Statement s;
	s.getdetails1();
	s.getdetails2();
	s.getdetails();
	s.disp1();
	s.disp2();
	s.dispfinal();
 
	
	
	return 0;
}
