// Ernesto Murillo - display menu for payment types

#include <iostream>
using namespace std;

int main()
{
	//declare variable
	int ptype = 0;

	//enter input
	cout << "\t\tPlease Enter Payment Type:\n";
	cout << "1 - Cash or Check\n";
	cout << "2 - Visa or Master Card\n";
	cout << "3 - Debit Card\n";
	cin >> ptype;

	//display output
	switch (ptype)
	{
	case 1:	
		cout << "1 Cash or Check Payment" << endl;
		break;
			
	case 2:	
		cout << "2 Visa or Master card Payment" << endl;
		break;
			
	case 3:	
		cout << "3 Debit Card Payment" << endl;
		break;
	
	default: 
		cout << "Invalide Selection" << endl;
	} //end switch
	
	system("pause");
	//return 0;

} //end of main function


