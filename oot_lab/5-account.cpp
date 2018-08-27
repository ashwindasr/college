#include <iostream>
using namespace std;

class Account
{
	private:
		char name[25];
		int accno;
		double balance;
	
	public:
		void create(int x);
		void deposit();
		void withdraw();
		void bal();
};
void Account::create(int x)
{
	cout << "\nEnter your name: \n";
	cin >> name;
	balance=0;
	accno=x;
}
void Account::withdraw()
{
	int cash;
	cout << "\nEnter the amount to be withdrawn\n";
	cin >>  cash;
	if((balance-cash)<0)
		cout<<"\nCannot withdraw more than balance\n";
	else
		balance-=cash;
}
void Account::deposit()
{
	int cash;
	cout << "\nEnter the amount to be deposit\n";
	cin >> cash;
	balance+=cash;
}
void Account::bal()
{
	cout << "\nYour current balance is: " << balance;
}
int main()
{
	int a=1;
	int ch;
	int num;
	Account acc[100];
	while(1)
	{
		cout << "\n1.Create account\n2.Withdraw\n3.Deposit\n4.Display balance\n5.Exit\n\nEnter your choice";
		cin >> ch;
		if(ch==1)
		{
			acc[a].create(a);
			a+=1;
			
		}
		else if(ch==2)
		{
			cout << "\nEnter your account number";
			cin >> num;
			acc[num].withdraw();
		}
		else if(ch==3)
		{
			cout << "\nEnter your account number";
			cin >> num;
			acc[num].deposit();
		}
		else if(ch==4)
		{
			cout << "\nEnter your account number";
			cin >> num;
			acc[num].bal();
		}
		else if(ch==5)
			break;
		else
		cout << "\nInvalid character\n";
		
	}
	return 0;
	
}
