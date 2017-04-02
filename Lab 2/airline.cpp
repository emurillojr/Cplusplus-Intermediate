// Ernesto Murillo - Lab 2

#include<iostream>;
#include<string>;
#include<iomanip>;
#include<fstream>;
#include<algorithm>;
using namespace std;

//function prototype
void newAFD();
int FlightNumber();
int Passengers();
void getOrigin(string&);
void getDest(string&);
void getCode(string&);
void report(int, string, string, int, string);
void FileOut(int, string, string, int, string);
void Report();

int main()
{
	// declare variables
	int opselect = 0;

	do 
	{
		// Airline Flight Data menu
		cout << " Airline Flight Data menu.\n";
		cout << " 1- Flight Data \n";
		cout << " 2- Print Report \n";
		cout << " 3- Exit \n";
		cout << endl;
		cout << "Make a selection: ";
		cin >> opselect;

		switch (opselect)
		{
			//Flight Data
		case 1:
			newAFD();
			break;

			//Print report
		case 2:
			Report();
			break;

			//Exit
		case 3:
			return 0;

			//Default Error
		default:
			cout << "Invaild Selection.";
		}
	} 
	while (1);
} // end of main


// function to get flight number
int FlightNumber()
{
	int flightno = 0;
	do 
	{
		cout << "Enter Flight Number: ";
		cin >> flightno;
	} 
	while (flightno < 99 || flightno > 999);
	return flightno;
}

//function to get origin city
void getOrigin(string &origin)
{
	do 
	{
		cout << "Enter Origin City: ";
		getline(cin, origin, '\n');
	} 
	while (origin.size() == 0 || origin.size() > 15);

	//make it all CAPS
	transform(origin.begin(), origin.end(), origin.begin(), toupper);
}

//function to get destination
void getDest(string &destination)
{
	do 
	{
		cout << "Enter Destination: ";
		getline(cin, destination, '\n');
	} 
	while (destination.size() == 0 || destination.size() > 15);

	//make it all CAPS
	transform(destination.begin(), destination.end(), destination.begin(), toupper);
}


// function to get passenger number
int Passengers()
{
	int passengers = 0;

	do 
	{
		cout << "Enter # of Passengers: ";
		cin >> passengers;
	}
	while (passengers < 50 || passengers > 300);

	return passengers;
}

//function for code
void getCode(string &code)
{
	do
	{
		cout << "Enter Code.  O = On time  D = Delayed  C = Cancelled: ";
		cin >> code;
	}
	while (code != "o" && code != "O" && code != "D" && code != "d" && code != "C" && code != "c");

	transform(code.begin(), code.end(), code.begin(), toupper);
}


void report(int flightno, string origin, string destination, int passengers, string code)
{
	cout << left << setfill(' ') << setw(9) << "FLIGHT #" << " " << setw(15) << "ORIGIN" << " " << setw(15) << "DESTINATION" << " " << setw(12) << "PASSENGERS" << " " << setw(6) << "CODE" << endl;
	cout << left << setfill(' ') << setw(9) << flightno << " " << setw(15) << origin << " " << setw(15) << destination << " " << setw(12) << passengers << " " << setw(6) << code << endl;
}

void newAFD()
{
	int flightno = 0;
	int passengers = 0;
	string origin = "";
	string destination = "";
	string code = "";
	// Input Data

	// Enter Flight Number
	flightno = FlightNumber();
	cin.ignore(1);

	//Enter Name
	getOrigin(origin);

	//Enter Address
	getDest(destination);

	//Enter Passengers
	passengers = Passengers();
	cin.ignore(1);

	//Enter Code D C O
	getCode(code);

	//Write Out File
	FileOut(flightno, origin, destination, passengers, code);

	//Enter Report
	report(flightno, origin, destination, passengers, code);

	system("pause");
}

void FileOut(int flightno, string origin, string destination, int passengers, string code)
{
	ofstream outFile;
	outFile.open("FLIGHT.dat", ios::app);

	if (outFile.is_open())
	{
		outFile << flightno << '#' << origin << '#' << destination << '#' << passengers << '#' << code << '#' << endl;
	}

	else
	{
		cout << "File could not be opened." << endl;
	}

	outFile.close();
}

void Report()
{
	int flightno = 0;
	string origin = "";
	string destination = "";
	int passengers = 0;
	string code = "";

	ifstream inFile;
	inFile.open("FLIGHT.dat", ios::in);
	if (inFile.is_open())
	{
		cout << left << setfill(' ') << setw(9) << "FLIGHT #" << " " << setw(15) << "ORIGIN" << " " << setw(15) << "DESTINATION" << " " << setw(12) << "PASSENGERS" << " " << setw(6) << "CODE" << endl;
		inFile >> flightno;
		while (!inFile.eof())
		{
			inFile.ignore(1);
			getline(inFile, origin, '#');
			getline(inFile, destination, '#');
			inFile >> passengers, '#';
			inFile.ignore(1);
			getline(inFile, code, '#');
			inFile.ignore(1);

			cout << left << setfill(' ') << setw(9) << flightno << " " << setw(15) << origin << " " << setw(15) << destination << " " << setw(12) << passengers << " " << setw(6) << code << endl;
			inFile >> flightno;
		}
	}
	else
	{
		cout << "File not opened" << endl;
	}

	inFile.close();
} // end of void Report
