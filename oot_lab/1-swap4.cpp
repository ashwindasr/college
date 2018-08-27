#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}



int main()
{
	int a,b;
	cout << "\nEnter 2 numbers\n" ;
	cin >> a >> b ;
	
	cout << "\nBefore swap :";
	cout << "\n a= " << a;
	cout << "\n b= " << b;
	
	swap(&a,&b);
	
	cout << "\nAfter swap :";
	cout << "\n a= " << a;
	cout << "\n b= " << b;
}
