#include <iostream>
#include <string.h>
using namespace std;
class Person
{
	protected:
		string name;
		int code;	
	public:
		void getpdata();
};
void Person::getpdata()
{
	getchar();
	cout<<"\nEnter your name: ";
	getline(cin,name);
	cout<<"\nEnter code: ";
	cin>>code;
}
class Account:virtual public Person
{
	protected:
		int pay;	
	public:
		void getacdata();
};
void Account::getacdata()
{
	cout<<"\nEnter pay: ";
	cin>>pay;
}
class Admin:virtual public Person
{
	protected:
		int experience;	
	public:
		void getaddata();
};
void Admin::getaddata()
{
	cout<<"\nEnter experience: ";
	cin>>experience;
}
class Master:public Account, public Admin
{
	public:
		void dispdata();
		int find(int x);	
		void modify();
};
void Master::dispdata()
{
	cout<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Code: "<<code<<endl;
	cout<<"Pay: "<<pay<<endl;
	cout<<"Experience: "<<experience<<endl;
}
int Master::find(int x)
{
	if(x==this->code)
		return 1;
	return 0;
}
void Master::modify()
{
	int ch;
	cout<<"1.Name\n2.Code\n3.Pay\n4.Experience\n\nEnter your choice: ";
	cin>>ch;
	if(ch==1)
	{
		getchar();
		cout<<"Enter your name: ";
		getline(cin,name);
	}
	else if(ch==2)
	{
		cout<<"Enter your code: ";
		cin>>code;
	}
	else if(ch==3)
	{
		cout<<"Enter your pay: ";
		cin>>pay;
	}
	else if(ch==4)
	{
		cout<<"Enter your experience: ";
		cin>>experience;
	}
	else
	cout<<"\nInvalid choice";
	
	cout<<"Data modified!"<<endl;
}
int main()
{
	Master *m=new Master[100];
	int ch;
	int x=-1;
	while(1)
	{
		cout<<"\n1.Enter\n2.Update\n3.Display\n4.Exit\n\nEnter your choice: ";
		cin>>ch;
		if(ch==1)
		{
			x+=1;
			(*(m+x)).getpdata();
			(*(m+x)).getacdata();
			(*(m+x)).getaddata();
		}
		else if(ch==2)
		{
			int y;
			cout<<"Enter code: ";
			cin>>y;
			int flag=0;
			for(int i=0;i<=x;i++)
			{
				if(((*(m+i)).find(y)==1))
				{
					(*(m+i)).modify();
					flag=1;
					break;
				}
					
			}
			if(!flag)
			{
				cout<<"\nData not available"<<endl;
			}
			
		}
		else if(ch==3)
		{
			int y;
			cout<<"Enter code: ";
			cin>>y;
			int flag=0;
			for(int i=0;i<=x;i++)
			{
				if(((*(m+i)).find(y)==1))
				{
					(*(m+i)).dispdata();
					flag=1;
				}
					
			}
			if(!flag)
			{
				cout<<"\nData not available"<<endl;
			}
		}
		else if(ch==4)
			break;
		else
			cout<<"\nInvalid Choice\n";
	}
	return 0;
}

