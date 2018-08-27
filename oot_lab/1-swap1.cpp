#include <iostream>
using namespace std;

void swap()
{
	int a,b,t;
	cout << "\nEnter 2 numbers\n" ;
	cin >> a >> b ;
	
	t=a;
	a=b;
	b=t;
	cout << "First num: " << a << endl;
	cout << "Second num: " << b << endl;
}

int main()
{
	swap();
	
	return 0;
}

