#include <iostream>
using namespace std;

int main()
{
	int a,b,ch;
	cout << "\n1.Addotion\n2.Subtraction\n3.Multiplication\n4.Division\n";
	cin >> ch;
	cout << "\nEnter the two numbers\n";
	cin >> a >> b;
	
	if(ch==1)
		cout << "\nSum= " << a+b;
	else if(ch==2)
		cout << "\nDifference= " << a-b ;
	else if(ch==3)
		cout <<"\nProduct= " << a*b ;
	else if(ch==4)
		cout << "\nQuotient= " << a/b	;
	else
		cout << "\nInvalid character ";
		
	return 0;
}
