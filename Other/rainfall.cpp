// Ernesto Murillo - calculates and displays the total rainfall

#include <iostream>;
#include <fstream>;
using namespace std;

//function prototype
// add const for example.

float calcTotal(float []);

int main()
{
	//declare variable
	int x = 0;    //keeps track of subscripts

	//declare array
	float rainFall[12] = {0.0};

	//declare file object and open file
	ifstream inFile;
	inFile.open("rainfall.dat", ios::in);

	if (inFile.is_open())
	{
		//fill array with file data
		while (x < 12 && !inFile.eof())
		{
			inFile >> rainFall[x];
			x = x + 1;
		} //end while
		inFile.close();    //close file

		//display total rainfall
		cout << "Total rainfall: " << calcTotal(rainFall) << endl;
	}
	else
		cout << "File could not be opened" << endl;
	system("pause");
	//return 0;
	//end if
} //end of main function

//*****program-defined functions*****
float calcTotal(float r[])
{
	int x       = 0;    //keeps track of subscripts
	float total = 0.0;  //accumulator

	while (x < 12)
	{
		total = total + r[x];
		x = x + 1;
	} //end while
	return total;
} //end of calcTotal function
