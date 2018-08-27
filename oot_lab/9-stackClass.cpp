#include <iostream>
using namespace std;

class Stack
{
	private:
		int top;
		int *a;
		int size;
	public:
		Stack(int s);
		void push();
		void pop();
		void display();
	
};
Stack::Stack(int s)
{
	top=-1;
	a=new int[sizeof(int)*size];
	size=s;
}

void Stack::pop()
{
	if(top==-1)
		cout << "\nStack Underflow!\n";
	else
		cout << "\nPopped Element:\n" << a[top--];
}
void Stack::push()
{
	if((top+1)==size)
		cout << "\nStack Overflow!\n";
	else
	{
			cout << "\nEnter the number to push into the stack\n";
			cin >> a[++top];
	}
}
void Stack::display()
{
	if(top==-1)
		cout << "\nStack underflow!";
	else
	{
		cout << "\nThe current stack:\n";
		int i;
		for(i=top;i>=0;i--)
			cout << a[i] <<"\n";
	}
}
int main()
{
	int s;
	cout << "\nEnter the size of the stack\n";
	cin >> s;
	Stack stk(s);						//class name: Stack  object name: stk
	
	char choice;
	while(1)
	{
		cout << "\n***** Stack Operations *****\n1.Push element into the stack\n2.Pop element from the stack\n3.Display the current stack\n4.Exit\n\nEnter the choice\n";
		cin >> choice;
		if(choice=='1')
			stk.push();
		else if(choice=='2')
			stk.pop();
		else if(choice=='3')
			stk.display();
		else if(choice=='4')
			break;
		else
			cout << "\nInvalid character please try again or press 4 to exit.\n";		
	}
	
	return 0;
}
