/*The aim of this program is to demonstrate function overloading by calculating the volumes of a sphere, cube and a rectangular box*/


#include <iostream>
using namespace std;

class Volume
{
	public:
		void volume(float a);
		void volume(double r);
		void volume(float l,float b,float h);

};
void Volume::volume(float a)
{
	cout << "\nThe volume of the cube is " << a*a*a <<" cubic metres";
}
void Volume::volume(double r)
{
	cout << "\nThe volume of the sphere is " << (4/3)*3.14*r*r*r << " cubic metres";
}
void Volume:: volume(float l,float b,float h)
{
	cout << "\nThe volume of the rectangular box is " << l*b*h << " cubic metres";
	
}
int main()
{
	Volume vol;
	char ch;
	cout << "\n1.Calculate volume of cube\n2.Calculate volume of sphere\n3.Volume of rectangular box\nEnter your choice\n";
	cin >> ch;
	if(ch=='1')
		{
			float a;
			cout << "\nEnter the side of the cube\n";
			cin >> a;
			vol.volume(a);
		}
	else if(ch=='2')
		{
			double r;
			cout << "\nEnter the radius of the sphere\n";
			cin >> r;
			vol.volume(r);
			
		}
	else if(ch=='3')
		{
			float l,b,h;
			cout << "\nEnter the length, breadth and height of the rectangle\n";
			cin >> l >> b >> h ;
			vol.volume(l,b,h);
			
		}
	else
		cout << "\nInvalid character. Please try again.\n";
	
	return 0;
}

