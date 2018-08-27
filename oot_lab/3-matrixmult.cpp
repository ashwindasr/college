#include <iostream>
using namespace std;


int main()
{
	int x,y,m,n;
	cout << "\nEnter the number of rows and columns of the 1st matrix" <<endl ;
	cin >> x >> y ;
	// variable x is used to store the number of rows of the 1st matrix 
	// variable y is used to store the number of columns of the 1st matrix 
	cout << "\nEnter the number of rows and columns of the 2nd matrix" <<endl ;
	cin >> m >> n ;
	// variable m is used to store the number of rows of the 2nd matrix 
	// variable n is used to store the number of columns of the 2nd matrix 
	//nt a[10][10];
	//int b[10][10];
	
	int a[x][y];
	int b[m][n];
	int c[x][n];
	cout <<"\nEnter the elements of the first matrix";
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			cin >> a[i][j] ;
		}
	}
	cout <<"\nEnter the elements of the second matrix";   
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> b[i][j] ;
		}
	}
	


	if(y!=m)
	{
		cout <<"\nMultiplication not possible";
		
	}
	else
	
	{
			
	for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < n; j++)
            {
               *(*(c+i)+j) = 0;
                for (int k = 0; k < m; k++)
                {
                    *(*(c+i)+j) = *(*(c+i)+j) + *(*(a+i)+k) * *(*(b+k)+j);
                }
            }
        }
	}
	
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			cout << c[i][j] << " ";
		}
		cout <<endl;
	}
	return 0;
}


