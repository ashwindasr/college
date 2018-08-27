// Aim: To demonstrate constructor overloading

#include <iostream>
using namespace std;

class Volume
{
	
	private:
		double volume;
		
	public:
		void display();
		Volume(float a)
		{
			volume=a*a*a;
		}
		Volume(double r)
		{
			volume=(4/3)*3.14*r*r*r;
		}
		Volume(float l, float b, float h)
		{
			volume=l*b*h;
		}
	
};

//function display to display the volume of the selected shape
void Volume::display()
{
	cout << volume << " cubic metres";
}
int main()
{
	int i=1;
	char ch;
	cout << "\n1.Calculate volume of cube\n2.Calculate volume of sphere\n3.Volume of rectangular box\nEnter your choice\n";
	cin >> ch;
	if(ch=='1')
		{
			float a;
			cout << "\nEnter the side of the cube\n";
			cin >> a;
			Volume vol(a);
			cout << "\nThe volume of the cube is: ";
			vol.display();
		}
	else if(ch=='2')
		{
			double r;
			cout << "\nEnter the radius of the sphere\n";
			cin >> r;
			Volume vol(r);
			cout << "\nThe volume of the sphere is: ";
			vol.display();
			
		}
	else if(ch=='3')
		{
			float l,b,h;
			cout << "\nEnter the length, breadth and height of the rectangle\n";
			cin >> l >> b >> h ;
			Volume vol(l,b,h);
			cout << "\nThe volume of the rectangular box is: ";
			vol.display();
			
		}
	else
		cout << "\nInvalid character. Please try again.\n";
	
			
	return 0;
}
