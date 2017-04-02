// Ernesto Murillo  - lottery random number generator

//built in functions
#include <iostream>;
#include <ctime>;
#include <cstdlib>;
#include <string>;
#include <iomanip>;
#include<algorithm>;
using namespace std;

int main()
{
	// declare variables
	int number = 0;
	int counter = 0;
    string name = "";
    int acct_number = 0;

	// Enter player card number
	cout<<" \t Enter card number: ";
    cin>>acct_number;	
    cin.ignore(1);           

	// Enter players name
	cout<<" \tEnter lottery players name: ";
    getline(cin,name);	
    system("cls");
	transform(name.begin(),name.end(),name.begin(),toupper); 
	cout<<"\t"<< name<<" quick picks are: \n";

    // seed
	srand(time(NULL));
	for (counter = 1; counter <= 6; counter++)
		{  //random number generator
			number = 1 + rand()%(99 -1 +1);
			cout<<"\tnumber"<< counter << " "<<fixed<<setprecision(0)<<number<< endl;
		}

	system("pause");
	//return 0;
}
