// Ernesto Murillo  - displays the present value of a series of periodic payments

#include <iostream>;
#include <cmath>;
#include <fstream>; 
using namespace std;

int main()
{
	const int PAYMENT = 360;
	const int TERM    = 48;
	float rate        = 0.0;
	float principal   = 0.0;
	ofstream outFile; 
	outFile.open("T7AppE05.dat");

	//enter input items
	cout << "Enter the annual interest rate: ";
	cin >> rate;
	rate = rate / 12;

	//calculate present value (principal)
	principal = PAYMENT * (1 - pow(rate + 1, -TERM)) / rate;
	
	//display output items
	cout << fixed;
	cout.precision(0);
	cout << "You can borrow up to $" << principal << endl;
	outFile << fixed;
	outFile.precision(0);
	outFile << "You can borrow up to $" << principal << endl; 
	outFile.close();

	system("pause");
	//return 0;
}	//end of main function

