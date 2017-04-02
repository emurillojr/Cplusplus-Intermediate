// Ernesto Murillo - show sample pass by value

#include <iostream>
int getNumber();
int calcCube(int);
using namespace std;

int main()
{
	int number = 0;
	int cubeNumber = 0;
	number = getNumber();
	cubeNumber = calcCube(number);
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

int calcCube(int num)
{
	return num * num * num;
}
