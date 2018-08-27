#include <iostream>
#include <string.h>
using namespace std;

class Person
{
	protected:
		string name;
		int age;
	public:
		void getpdata();
		void disppdata();
};
void Person::getpdata()
{
	getchar();
	cout<<"\nEnter your name: ";
	getline(cin,name);
	cout<<"\nEnter age: ";
	cin>>age;
}
void Person::disppdata()
{
	cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;
}
class Employee:public Person
{
	protected:
		float salary;
		string dept_name;
	public:
		void getedata();
		void dispedata();	
};
void Employee::getedata()
{
	cout<<"\nEnter your salary: ";
	cin>>salary;
	cout<<"\nEnter department name: ";
	getchar();
	getline(cin,dept_name);
}
void Employee::dispedata()
{
	cout<<"Name: "<<name<<endl<<"Salary: "<<salary<<endl<<"Department: "<<dept_name<<endl;
}
class Student:public Person
{
	protected:
		int roll_no;
		string grade;
	public:
		void getsdata();
		void dispsdata();
};
void Student::getsdata()
{
	cout<<"\nEnter roll no: ";
	cin>>roll_no;
	cout<<"\nEnter grade: ";
	getchar();
	getline(cin,grade);
}
void Student::dispsdata()
{
	cout<<"Name: "<<name<<endl<<"Roll no: "<<roll_no<<endl<<"Grade: "<<grade<<endl;
}
int main()
{
	int c;
	cout<<"1.Employee\n2.Student\n\nEnter your choice: ";
	cin>>c;
	if(c==1)
	{
		Employee e;
		e.getpdata();
		e.getedata();
		e.dispedata();
	}
	else
	{
		Student s;
		s.getpdata();
		s.getsdata();
		s.dispsdata();
	}
	
	return 0;
}
	

