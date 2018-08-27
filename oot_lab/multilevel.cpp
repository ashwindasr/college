#include <iostream>
#include <string.h>
using namespace std;

class Student
{
	protected:
		string name;
		int roll_no;
	public:
		void getsdata();
		void dispsdata();
};
void Student::getsdata()
{
	getchar();
	cout<<"Enter you name: ";
	getline(cin,name);
	cout<<"\nEnter roll no: ";
	cin>>roll_no;
}
void Student::dispsdata()
{
	cout<<"Name: "<<name<<endl<<"Roll no: "<<roll_no<<endl;
}
class Test:public Student
{
	protected:
		float mark[5];
	public:
		void gettdata();
		void disptdata();
};
void Test::gettdata()
{
	for(int i=0;i<5;i++)
	{
		cout<<"\nMark of subject "<<i+1<<": ";
		cin>> mark[i];
	}
}
void Test::disptdata()
{
	cout<<"Name: "<<name<<endl<<"Roll no: "<<roll_no<<endl<<"Marks: "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Mark of subject "<<i+1<<": ";
		cout<<mark[i];
		cout<<endl;
	}
}
class Result:public Test
{
	protected:
		float result;
	public:
		Result()
		{
			result=0;
		}
		void calculate();
		void disprdata();
	
};
void Result::calculate()
{
	for(int i=0;i<5;i++)
		result+=mark[i];
	result/=5;
}
void Result::disprdata()
{
	cout<<"Name: "<<name<<endl<<"Roll no: "<<roll_no<<endl<<"Marks: "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"\nMark of subject "<<i+1<<": ";
		cout<<mark[i];
	}
	cout<<endl;
	cout<<"Result: "<<result<<"%";
}
int main()
{
	int c;
	cout<<"1.Student\n2.Test\n3.Result\n\nEnter your choice: ";
	cin>>c;
	if(c==1)
	{
		Student s;
		s.getsdata();
		s.dispsdata();
	}
	else if(c==2)
	{
		Test t;
		t.getsdata();
		t.gettdata();
		t.disptdata();
	}
	else
	{
		Result r;
		r.getsdata();
		r.gettdata();
		r.calculate();
		r.disprdata();
	}
	
	return 0;
}
