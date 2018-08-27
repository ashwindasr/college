#include <iostream>
using namespace std;

class Bracket
{
	private:
		int size;
	public:
		void operator[](int x);
		void read();
	
};

void Bracket::operator[](int x)
{
	if(x>=size)
		cout << "\nArray index out of bounds\n";
	else
		cout << "\nWithin bounds\n";
}
void Bracket::read()
{
	cout<<"\nEnter the size\n";
	cin >> size;
}
int main()
{
	Bracket obj;
	obj.read();
	obj[5];
	
	return 0;
}

