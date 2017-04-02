// Ernesto Murillo -  cube variable example of call-by-ref using pointer argument

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int getNumber();
int calcCube(int *);

using namespace std;

int main()
{
	int number = 0;
	int cubeNumber = 0;
	number = getNumber();
	cubeNumber = calcCube(&number);
	cout<< "Number to be cubed is : "<<number <<" and its cubed value is : "<<cubeNumber<< endl;

	system("pause");
	//return 0;
}

int getNumber()
{
	int numb = 0;
	cout<<"Enter number: ";
	cin >> numb;
	return numb;
}

int calcCube(int *numPtr)
{
	return *numPtr * *numPtr * *numPtr;
}
