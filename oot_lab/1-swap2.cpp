#include <iostream>
using namespace std;

void swap(int a,int b)
{
	int t=a;
	a=b;
	b=t;
	cout << "First num: " << a << endl;
	cout << "Second num: " << b << endl;
}



int main()
{
	int a,b;
	cout << "\nEnter 2 numbers\n" ;
	cin >> a >> b ;
	swap(a,b);
}
