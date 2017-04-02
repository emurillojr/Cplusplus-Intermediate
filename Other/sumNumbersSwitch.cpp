// Ernesto Murillo  - sum of numbers using switch 


#include <iostream>;
using namespace std;

int main()
{
	  //declare variable
	  int opselect;
	  double fnum, snum;

	  //enter input
	  cout << "\nPlease type in two numbers: ";
	  cin  >> fnum >> snum;
	  cout << "Enter a select code: ";
	  cout << "\n        1 for addition";
	  cout << "\n        2 for multiplication";
	  cout << "\n        3 for division : ";
	  cin  >> opselect;

	  //display output
	  switch (opselect)
	  {
		case 1:
		  cout << "The sum of the numbers entered is " << fnum+snum << endl;
		  break;
		case 2:
		  cout << "The product of the numbers entered is " << fnum*snum << endl;
		  break;
		case 3:
		  cout << "The first number divided by the second is " << fnum/snum << endl;
		  break;
		default:
		  cout << "Invalid Selection";
	   }     // end of switch

	system("pause");	
	//return 0;
	}
