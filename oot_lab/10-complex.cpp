// Program to calculate the sum of 2 complex numbers using operator overloading


#include <iostream>
using namespace std;

class Complex
{
	private:
		float a;
		float b;
		
	public:
		void input();
		void display();
		Complex operator +(Complex &x);

};

void Complex::input()
{
	cout<< "\nReal part: \n";
	cin >> a;
	cout<< "\nImaginary: \n";
	cin >> b;
}
void Complex::display()
{
	cout << "\nThe sum of the complex numbers: "<< a << "+" << b << "i";
}
Complex Complex::operator +(Complex &x)
{
	Complex temp;
	temp.a=a+x.a;
	temp.b=b+x.b;
	return temp;
}
int main()
{
	Complex a,b;
	cout << "\nEnter the first complex number:\n";
	a.input();
	cout << "\nEnter the second complex number:\n";
	b.input();
	Complex c = a+b;
	c.display();
	
	return 0;

}
