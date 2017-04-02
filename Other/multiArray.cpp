// Ernesto Murillo
#include <iostream>
using namespace std;
const int constCols = 2;

void fillUp(int a[] [constCols], int rows)
{	
    int fillRow = 0;
    int fillCol = 0;
    cout<<"Enter "<<rows<<" rows of "<<constCols<<" columns"<<endl;

    while (fillRow < rows)
	{
	  fillCol = 0;
	  while (fillCol < constCols)
	    {
		cout<<"Enter row "<<fillRow+1<<" of "<<fillCol+1<<": "; 
		cin>> a[fillRow] [fillCol];
		++fillCol;
		cout<<endl;
	    }
	++fillRow;
	cout<<"Enter Additional Info for row "<<fillRow<<endl;
	}
}

void printOut(int a[] [constCols], int rows)
{	
    int fillRow = 0;
    int fillCol = 0;

    cout<<endl<<"Print Rows and Columns:\n";
    while (fillRow < rows)
	{
	 fillCol = 0;
	 while (fillCol < constCols)
	   {
	     cout<< a[fillRow] [fillCol];
	     ++fillCol;
	     cout<<'\t';
	   }
	cout<<'\n';
	++fillRow;
	}
}

int main( )
{
    int rows = 0;
	cout<<"Enter number of rows ";
	cin>> rows;
	int a[rows][constCols];

  	fillUp(a,rows);
	printOut(a,rows);
	
	system("pause");
    //return 0;
}//End Main

