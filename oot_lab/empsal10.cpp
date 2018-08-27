
#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
	protected:
		string name;
		int id;
		long int phone;
	public:
		void gete();
};
void Employee::gete()
{
	getchar();
	cout<<"Enter your name: ";
	getline(cin,name);
	cout<<"Enter your employee id: ";
	cin>>id;
}
class Salary:public Employee
{
	private:
		float sal;
	public:
		void gets();
		void disp();
		int find(int x);	
};
void Salary::gets()
{
	cout<<"Enter your current monthly salary: ";
	cin>>sal;
}
void Salary::disp()
{
	cout<<"Name: "<<name<<endl;
	cout<<"ID: "<<id<<endl;
	cout<<"Monthly salary: "<<sal<<endl;
	cout<<"Annual salary: "<<sal*12<<endl;
}
int Salary::find(int x)
{
	if(x==this->id)
		return 1;
	return 0;
}
int main()
{
	Salary *s;
	s=new Salary[10];
	int ch;
	int x=-1;
	while(1)
	{
		cout<<"1.Enter\n2.Display\n\nEnter your choice: ";
		cin>>ch;
		if(ch==1)
		{
			x+=1;
			(*(s+x)).gete();
			(*(s+x)).gets();
		}
		else
		{
			int y;
			cout<<"Enter employee ID: ";
			cin>>y;
			for(int i=0;i<=x;i++)
			{
				if(((*(s+i)).find(y)==1))
					(*(s+i)).disp();
			}
			cout<<endl;
		}
	}
	return 0;
	
}
