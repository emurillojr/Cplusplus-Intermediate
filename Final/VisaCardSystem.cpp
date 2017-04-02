/*
Ernesto Murillo  Final Project
Advanced C++
Visa Card Menu System
Entering ssn name, address, city, state, zip, visa #.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <conio.h>
using namespace std;

struct MemberInfo   // structure
{
	long ssn;
	string name;
	string address;
	string city;
	string state;
	int zipcode;
	int visa;
};


const string vcd = "Visa Card System";
const string nai = "New Account Information";
const string fm = "Find an Existing Member";
const string amr = "All Members Report";
const int NUMEL = 50;   // const variable -unable to change

//Function Prototypes
long SSN();
void newVisa();
void getName(string&); 
void getAddress(string&);
void getCity(string&);
void getState(string&);
int  getZipcode();
int visaCard();
void fileOut(long, string, string, string, string, int, int); 
void Report();
void findMember();
void bubbleSort(MemberInfo[], int);
int binarySearch(MemberInfo[], int, string);
void transformFirstLetterOfEveryWord(char&);




int main()
{
	int opselect = 0;

	do {
		//Visa Menu
		cout << setw(33) << vcd << endl << endl << endl;
		cout << "\t1 -Enter New Account Information.\n";
		cout << "\t2 -Find an Existing Member.\n";
		cout << "\t3 -Print a Membership Report.\n";
		cout << "\t4 -Exit." << endl << endl << endl;
		cout << setw(21) << "Make a Selection: ";
		cin >> opselect;
		system("cls");

		switch (opselect)
		{
		case 1:  //Enter New Account Information
			newVisa();
			break;
	
		case 2:
			findMember();  //Find Member
			break;

		case 3:  //Print Report
			system("cls");
			Report();
			break;

		case 4:   //Exit
			return 0;

		default:   //Error
			cout << "Invalid Selection";

		} //End of Switch

	} while (1);   //end of do while

}  // end of main



// function to get ssn
   long SSN()
   {
   long ssn = 0;
   do  
   {
   cout << "SSN (9 digit number):     ";
   cin >> ssn;
   } while (ssn<100000000 || ssn>999999999);

   return ssn;
   }
  
// function to get full name
void getName(string &name)
{
	int position = 0;

	cout << "Name (20 characters):     ";
	getline(cin, name, '\n');
	while (name.size() == 0 || name.size()>25)
	{
		cout << "Name (20 characters):     " << endl;
		getline(cin, name, '\n');
	}

	transform(name.begin(), name.end(), name.begin(), tolower);  // change all words in name string to all lower case
	name[0] = toupper(name[0]);  // first letter of word in name string to upper case
	for_each(name.begin() + 1, name.end(), transformFirstLetterOfEveryWord); //fuction to change rest of words in string to uppercase

}

// function to get address
void getAddress(string &address)
{
	int position = 0;

	cout << "Address (25 characters):  ";
	getline(cin, address, '\n');
	while (address.size() == 0 || address.size()>25)
	{
		cout << "Address (25 characters):  " << endl;
		getline(cin, address, '\n');
	}

	transform(address.begin(), address.end(), address.begin(), tolower);  // change all words in address string to all lower case
	address[0] = toupper(address[0]); // first letter of address string to upper case
	for_each(address.begin() + 1, address.end(), transformFirstLetterOfEveryWord); //fuction to change rest of words in string to uppercase

}

// function to get city
void getCity(string &city)
{
	int position = 0;

	cout << "City (16 characters):     ";
	getline(cin, city, '\n');
	while (city.size() == 0 || city.size()>16)  //pretest while 
	{
		cout << "City(16 characters):     " << endl;
		getline(cin, city, '\n');
	}

	transform(city.begin(), city.end(), city.begin(), tolower); // change all words in city string to all lower case
	city[0] = toupper(city[0]);  // first letter of city string to upper case
	for_each(city.begin() + 1, city.end(), transformFirstLetterOfEveryWord); //fuction to change rest of words in string to uppercase

}

// function to get state
void getState(string &state)
{
	cout << "State (RI,MA,CT):         ";
	getline(cin, state, '\n');
	while (state != "RI" && state != "MA" && state != "CT" && state != "ri" && state != "ma" && state != "ct") 
	{
		cout << "State (RI,MA,CT):         ";
		getline(cin, state, '\n');
	}

	transform(state.begin(), state.end(), state.begin(), toupper); // change state string to all uppercase
}

//funstion to get zipcode
int getZipcode()
{
	int zipcode = 0;
	cout << "Zip (01000-99900):        ";
	cin >> zipcode;

	while (zipcode < 01000 || zipcode > 99900)
	{
		cout << "Zip (01000-99900):        ";
		cin >> zipcode;

	}

	return (zipcode);
}


//function to get new visa information
void newVisa()
{
	long ssn = 0;
	string name = " ";
	string address = " ";
	string city = " ";
	string state = " ";
	int zipcode = 0;
	int visa = 0;
	char answer;
	
	cout << setw(33) << vcd << endl;
	cout << setw(37) << nai << endl << endl;
	cout << "Demographic Information:\n";

	ssn = SSN();  //Enter SSN
	cin.ignore(1);   // ignores # sign
	getName(name); //Enter Name
	getAddress(address); //Enter Address
	getCity(city); //Enter City
	getState(state); //Enter State
	zipcode = getZipcode(); //Enter Zipcode

	do
	{
		cout << "Verify Information (Y/N): ";
		cin >> answer;
		switch (answer)
		{
		case 'y':
		case 'Y':
			visa = visaCard();
			fileOut(ssn, name, address, city, state, zipcode, visa);
			system("pause");
			system("cls");
		
		case 'n':
		case 'N':
			system("cls");
			return;   //return to main
	
		default:   //Error
			cout << "Invalid Selection";

		} // end of switch answer

	} while ('n');   //end of do while

	visa = visaCard();
	fileOut(ssn, name, address, city, state, zipcode, visa);
	system("pause");
	system("cls");

}

void fileOut(long ssn, string name, string address, string city, string state, int zipcode, int visa)
{
	ofstream outFile;
	outFile.open("visa.dat", ios::app);
	if (outFile.is_open())
	{
		outFile << ssn<< '#' << name << '#' << address << '#' << city << '#' << state << '#' << zipcode << '#' << visa << '#' << endl;
	}
	else
	{
		cout << "File could not be opened." << endl;
	}
	outFile.close();
}

void Report()
{
	long ssn = 0;
	string name = " ";
	string address = " ";
	string city = " ";
	string state = " ";
	int zipcode = 0;
	int visa = 0;
	ifstream inFile;
	inFile.open("visa.dat", ios::in);
	if (inFile.is_open())
	{
		cout << setw(43) << vcd << endl;
		cout << setw(44) << amr << endl << endl << endl;
		cout << left << setfill(' ') << setw(20) << "Name" << " " << setw(25) << "Address" << " " << setw(16) << "City" << " " << setw(2) << "St" << " " << setw(5) << "Zip" << "  " << setw(6) << " Visa #" << endl;


		inFile >> ssn;

		while (!inFile.eof())
		{
			inFile.ignore(1);
			getline(inFile, name, '#');
			getline(inFile, address, '#');
			getline(inFile, city, '#');
			getline(inFile, state, '#');
			inFile >> zipcode;
			inFile.ignore(1);
			inFile >> visa;
			inFile.ignore(2);

			cout << left << setfill(' ') << setw(20) << name << " " << setw(25) << address << " " << setw(16) << city << " " << setw(2) << state << " " << setw(5) << setfill('0') << right << zipcode << "  " << setw(6) << setfill(' ') << visa << endl;

			inFile >> ssn;
		}
	}
	else
	{
		cout << "File not opened" << endl;
	}

	inFile.close();

	system("pause");
	system("cls");

}

int visaCard()
{
	int number = 0;
	srand(time(NULL));
	number = 10000 + rand() % (99999 - 10000 + 1);
	return number;
}


void findMember()
{

	long ssn = 0;
	string name = "";
	string address = "";
	string city = "";
	string state = "";
	int zipcode = 0;
	int visa = 0;
	int x = 0;
	int i = 0;
	MemberInfo ArrayName[NUMEL] = { 0,"","","","",0,0 };
	int location = 0;

	ifstream inFile;
	inFile.open("visa.dat", ios::in);
	if (inFile.is_open())
	{


		inFile >> ArrayName[x].ssn;

		while (x < NUMEL && !inFile.eof())
		{
			inFile.ignore(1);
			getline(inFile, name, '#');
			ArrayName[x].name = name;
			getline(inFile, ArrayName[x].address, '#');
			getline(inFile, ArrayName[x].city, '#');
			getline(inFile, ArrayName[x].state, '#');
			inFile >> ArrayName[x].zipcode;
			inFile.ignore(1);
			inFile >> ArrayName[x].visa;
			inFile.ignore(2);
			x++;

			inFile >> ArrayName[x].ssn;
		}
	}
	else
	{
		cout << "File not opened" << endl;
	}

	inFile.close();

	bubbleSort(ArrayName, x);

	cout << setw(35) << vcd << endl;
	cout << setw(38) << fm << endl << endl;
	cout << "\nMember List, in ascending order:\n \n";
	for (i = 0; i < x; ++i)
		cout << "" << ArrayName[i].name << endl;

	//search for the member
	cin.ignore(1);
	cout << "\nEnter member name to locate: \n";
	cout << "Name (20 characters):     ";
	getline(cin, name);
	system("cls");
	location = binarySearch(ArrayName, x, name);
	if (location > -1)
		cout << setw(35) << vcd << endl
		<< setw(38) << fm << endl << endl
		<< "Report on Existing Memeber: \n"
		<< "\t\tName:            " << ArrayName[location].name << endl
		<< "\t\tAddress:         " << ArrayName[location].address << endl
		<< "\t\tCity:            " << ArrayName[location].city << endl
		<< "\t\tState:           " << ArrayName[location].state << endl
		<< "\t\tZipcode:         " << setw(5) << setfill('0') << right << ArrayName[location].zipcode << endl
		<< "\t\tVisa #           " << setfill(' ') << ArrayName[location].visa << endl << endl << endl;

	else
		cout << "There is no such member.  Member not found. \n\n";
	
	system("pause");
	system("cls");


}


void bubbleSort(MemberInfo StringData[], int numel)
{
	int i, j = 0;
	MemberInfo holdString = { 0,"","","","",0,0 };

	for (i = 0; i < (numel - 1); i++)
	{
		for (j = 1; j < numel; j++)
		{
			if (StringData[j].name < StringData[j - 1].name)
			{
				holdString = StringData[j];
				StringData[j] = StringData[j - 1];
				StringData[j - 1] = holdString;

			}
		}
	}


}



int binarySearch(MemberInfo StringData[], int size, string key)
{
	int left = 0;
	int right = 0;
	int midpt = 0;
	right = size - 1;

	while (left <= right)
	{
		midpt = (int)((left + right) / 2);
		if (key == StringData[midpt].name)
		{
			return midpt;
		}
		else if (key > StringData[midpt].name)
			left = midpt + 1;
		else
			right = midpt - 1;
	}// end while

	return -1;

}


void transformFirstLetterOfEveryWord(char& c)  //function to capitalize 1st letter of every word in string
{
	// if the previous character was a space, transform it toupper
	if ((*(&c - sizeof(char))) == ' ')
		c = toupper(c);
}
