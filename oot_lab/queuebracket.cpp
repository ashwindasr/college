#include <iostream>
using namespace std;

class QueueBracket
{
	private:
		int size,front,rear;
		int *a;
	public:
		int& operator[](int x);
		void insert();
		void del();
		void display();
		QueueBracket(int s)
		{
			front=rear=-1;
			size=s;
			a=new int[size];
		}
	
};

int& QueueBracket::operator[](int x)
{
	if(x>=size)
		cout << "\nArray index out of bounds\n";
	else
		cout << "\nWithin bounds\n";
}
void QueueBracket::insert()
{
	int x;
	cout<"\nEnter the number to input\n";
	cin>>x;
	if(front==-1)
	{
		front=rear=0;
		a[rear]=x;
	}
	else if((rear+1)<size)
		a[++rear]=x;
	
}
void QueueBracket::del()
{
	if(front<rear)
		{
			cout<< a[front++];
		}
	else if(front==-1)
	{
		cout<<"\nStack is empty!\n";
	}
	else
	{
		cout<<a[front];
		front=rear=-1;
	}
}
void QueueBracket::display()
{
	if(front==-1)
		cout<<"\nStack is empty!\n";
	else
	{
		for(int i=front;i<=rear;i++)
		cout<<a[i]<<"\n";
	}
}
int main()
{
	int s,choice;
	cout<<"\nEnter the size\n";
	cin >> s;
	QueueBracket obj(s);
while(1)
	{
		cout << "\n***** Queue Operations *****\n1.Insert element into the stack\n2.Delete element from the stack\n3.Display the current stack\n4.Exit\n\nEnter the choice\n";
		cin >> choice;
		if(choice==1)
			obj.insert();
		else if(choice==2)
			obj.del();
		else if(choice==3)
			obj.display();
		else if(choice==4)
			break;
		else
			cout << "\nInvalid character please try again or press 4 to exit.\n";		
	}
	
	return 0;
}

