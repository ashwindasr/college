#include <iostream>
using namespace std;

void swap(int a=1, int b=2)
{
	int t=a;
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

