//Ernesto Murillo - example of single dim array

#include <iostream>;
using namespace std;

void fillUp(int a[], int rows)
{	
    cout<<"Enter "<<rows<<" rows of grades."<<endl;
    for (int fillRow=0; fillRow <rows; fillRow ++)
	{
	  cout<<"Enter grade "<<fillRow+1<<" of "<<rows<<": "; 
	  cin>> a[fillRow];
	  cout<<endl;
	}
}

void printOut(int a[], int rows)
{	
    cout<<endl<<"Print Grades:\n";
    for (int fillRow=0; fillRow <rows; fillRow ++)
	{
	   cout<< a[fillRow]<<'\t';
	}
	cout<<'\n';
}

int main( )
{
	
	int rows = 0;
 	cout<<"Enter number of grades ";
	cin>> rows;
	int a[rows];

	fillUp(a,rows);
	printOut(a,rows);
	
	system("pause");
    //return 0;

}//End Main



