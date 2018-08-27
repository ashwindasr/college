//Program to implement matrix multiplication using classes
#include <iostream>
using namespace std;

class Mat
{
	private:
		int **u,**v,**c;
		int a,b,x,y;
	public:
		int get();
		void mult();
		void disp();
};
int Mat::get()
{
	int i,j;
	cout<<"Enter the dimensions of the 1st matrix: "<<endl;
	cin>>a>>b;
	cout<<"Enter the dimensions of the 2nd matrix: "<<endl;
	cin>>x>>y;
	if(b!=x)
	{
		cout<<"Multiplication not possible"<<endl;
		return 0;
	}
	cout<<"Enter the 1st matrix: "<<endl;
	u=new int*[a];
	for(i=0;i<a;i++)
	{
		u[i]=new int[b];
		for(j=0;j<b;j++)
			cin>>u[i][j];
	}
	cout<<"Enter the 2nd matrix: "<<endl;
	v=new int*[x];
	for(i=0;i<x;i++)
	{
		v[i]=new int[y];
		for(j=0;j<y;j++)
			cin>>v[i][j];
	}
	return 1;
}
void Mat::disp()
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
			cout<<*(*(c+i)+j)<<" ";
		cout<<endl;
	}
		
}
void Mat::mult()
{
	c=new int*[a];
	for(int i=0;i<a;i++)
	{
		c[i]=new int[y];
		for(int j=0;j<y;j++)
		{
			*(*(c+i)+j)=0;
			for(int k=0;k<x;k++)
			{
				*(*(c+i)+j)=*(*(c+i)+j)+*(*(u+i)+k) * *(*(v+k)+j);
			}
		}
	}
}
int main()
{
	Mat g;
	
	int c;
	c=g.get();
	if(c)
	{
		g.mult();
		g.disp();
	}	
	return 0;
} 
