// Ernesto Murillo - displays a water bill

#include <iostream>
#include <string>
using namespace std;

//function prototypes
void getInput(long &, string &, int &, int &);
void displayBill(string, int, float);

int main()
{	
	const float RATE = float(.00175);
	long account_number=0;
	string name  = "";
	int current  = 0;
	int previous = 0; 
	int gallons  = 0;
	float charge = 0.0;

	//enter input items
	getInput(account_number, name, current, previous);
	//calculate gallons used 
	
	//calculate water charge
	if (current > previous)
	{
		gallons = current - previous;
		charge = gallons * RATE;
	}
	else
	{
		gallons = current;
		charge  = gallons * RATE;
	}
	//display water bill
	displayBill(name, gallons, charge);
	
	system("pause");
	//return 0;
}	//end of main function

//*****program-defined functions*****
void getInput(long &account_number,string &cust, int &cur, int &prev)
{
	cout << "Customer account number:\t";
	cin >> account_number;
	cin.ignore(1);
	cout << "Customer name:\t";
	getline(cin, cust);
	cout << "Current reading:\t";
	cin >> cur;
	cout << "Previous reading:\t";
	cin >>prev;
}   //end of getInput function

void displayBill(string cust, int used, float amtDue)
{
	cout << fixed;
	cout.precision(2);
	cout << "Customer name: " << cust << endl;
	cout << "Gallons used: " << used << endl;
	cout << "Water charge: " << amtDue << endl;
}   //end of displayBill function
