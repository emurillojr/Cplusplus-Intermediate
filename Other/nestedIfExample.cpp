// Ernesto Murillo - Nested if example

#include <iostream>;
#include <string>;
using namespace std;

int main()
{
  int opselect = 0;
  double fnum, snum = 0.0;

  cout << "\nPlease type in two numbers: ";
  cin  >> fnum >> snum;
  cout << "Enter a select code: ";
  cout << "\n        1 for addition";
  cout << "\n        2 for multiplication";
  cout << "\n        3 for division : ";
  cin  >> opselect;

  if(opselect == 1)
	{
		cout << "The sum of the numbers entered is " << fnum+snum << endl;
	}
  else if(opselect == 2)
	{
		cout << "The product of the numbers entered is " << fnum*snum << endl;
	}
	else if(opselect == 3)
	{
		cout << "The first number divided by the second is " << fnum/snum << endl;
	}
    system("pause");
	//return 0;
}
