#include <iostream>
#include <string.h>
using namespace std;

virtual class person
{
	protected:
	 string name;
	 int code;
	public:
	 void getdata_person();	
};
void person::getdata_person()
{
	getchar();
	cout<<"\nEnter your name: ";
	getline(cin,name);
	cout<<"\nEnter your code: ";
	cin>>code;
}
class amount: public person
{
	protected:
	 float pay;
	public:
	 void getdata_amount();
};
void amount::getdata_amount()
{
	cout<<"\nEnter your salary: ";
	cin>>pay;
}
class admin: public person
{
	protected:
	 int exp;
	public:
	 void getdata_admin();
};
void admin::getdata_admin()
{
	cout<<"\nEnter your experience in years: ";
}
class master:public amount, public person
{
	public:
	 void disp();	
};
void master::disp()
{
	cout<<"Name: "<<name<<endln;
	cout<<"Code: "<<code<<endln;
	cout<<"Pay: "<<pay<<endln;
	cout<<"Experience: "<<exp<<endln;
}
int main()
{
	master m;
	m.getdata_person();
	m.getdata_amount();
	m.getdata_admin();
	m.disp();
	return 0;
}
