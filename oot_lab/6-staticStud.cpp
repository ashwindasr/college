#include <iostream>

using namespace std;

class Student 
{
	private:
		string stud_name;
		int stud_rollNo;
		string stud_Branch;
	public:
		static int objectCount;
		void read(int);
		void write() const;
};
int Student :: objectCount=0;

void Student::read(int roll)
{
	stud_rollNo=roll;
	cout << "\nEnter name:\n";
	getline(cin,stud_name);
	cout <<"\nEnter Branch:\n";
	getline(cin,stud_Branch);
}
void Student::write() const
{
	cout << "Name: " << stud_name <<"\Rollno: "<< stud_rollNo << "\nBranch: "<< stud_branch;
}
int main()
{
	Student a[50];
	while(1)
	{
		int ch;
		cout << "\n1.New student registration"
	}
}
