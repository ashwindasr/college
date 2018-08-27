#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
	protected:
		string name;
		int age;
		string compname;
	public:
		void getdetails();	
};

void Employee::getdetails()
{
	cout<<"Enter your name: ";
	getline(cin,name);
	cout<<"Enter your age: ";
	cin>>age;
	getchar();
	cout<<"Enter your company name: ";
	getline(cin,compname);
}
class Salary:public Employee
{
	private:
		float sal;
		float annualsal;
	public:
		void getsal();
		void disp();
	
};
void Salary::getsal()
{
	cout<<"Enter your salary: ";
	cin>>sal;
	annualsal=sal*12;
}
void Salary::disp()
{
	cout<<"Name: "<<name<<"\n";
	cout<<"Age: "<<age<<"\n";
	cout<<"Company name: "<<compname<<"\n";
	cout<<"Salary: "<<sal<<"\n";
	cout<<"Annual Salary: "<<annualsal<<"\n";
}
int main()
{
	Salary s;
	s.getdetails();
	s.getsal();
	s.disp();
}
