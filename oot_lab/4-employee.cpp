#include <iostream>
using namespace std;

class Employee
{
	private:
		char name[25];
		char designation[25];
		int age;
		float salary;
	
	public:
		void readEmp();
		void disp();
		
};
void Employee::readEmp()
{
	cout << "\nEnter your name\n";
	cin >>name;
	cout << "\nEnter your age\n";
	cin >> age;
	cout << "\nEnter your designation\n";
	cin >> designation;
	cout << "\nEnter your salary\n";
	cin >> salary;
}
void Employee::disp()
{
	cout << "\n Name: " << name;
	cout << "\n Age: " << age;
	cout << "\n Designation: " << designation;
	cout << "\n Salary: " << salary;
}
int main()
{
	int n;
	cout << "\nEnter the numebr of employees";
	cin >> n;
	Employee emp[n];
	for(int i=0;i<n;i++)
	{
		cout << "Enter the details of employee " <<i+1 ;
		emp[i].readEmp();
	}
	
	for(int i=0;i<n;i++)
	{
		cout << "The details of employee " <<i+1 <<"\n\n" ;
		emp[i].disp();
	}

	
	return 0;
}
