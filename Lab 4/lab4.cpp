// Ernesto Murillo  - Lab 4

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime> 
#include<cstdlib> 
#include<algorithm>
using namespace std;

struct MemberInfo   // structure
{
	int idnum;
	string lname;
	string fname;
	float gpa;
};


//function prototypes
void getlastNAME(string&);  // get last name string
void getfirstNAME(string&);  // get first name string
int idNUMBER();  //get student ID number int
float studentGPA(); //get student GPA with decimal float
void FileOut(int, string, string, float);
void Report(); // infile data 
const int NUMEL = 100;
void findStudent();
void bubbleSort(MemberInfo[], int); // [defines an array] <--starting address, will change
int binarySearch(MemberInfo[], int, int);

int main()
{
	// declare variables

	char answer;
	int opselect = 0;
	string lname = " ";
	string fname = " ";
	int idnum = 0;
	float gpa = 0.00;
	
	do
	{
		// Intro and Yes or No to continue first
		cout << "Welcome to the Registrars office of local college ABC.\n";
		cout << "You can use this program to enter or search for student data.\n\n";
		cout << "Do you want to continue? Type Y for YES or N for NO: ";
		cin >> answer;

		switch (answer)  //Yes or No switch 
		{
		case 'Y':
		case 'y':
			cout << endl;
			cout << "Please select an option below. \n\n";
			cout << "1- Enter New Student Data.\n";
			cout << "2- Find Student.\n";
			cout << "3- Student List Report.\n";
			cout << "4- Exit. \n\n";
			cout << "Make a selection: ";
			cin >> opselect;   //go to switch opselect
			cout << endl;

			switch (opselect)      //program menu 
			{
				//Enter Student Data
			case 1:

				idnum = idNUMBER();
				getlastNAME(lname);
				getfirstNAME(fname);
				gpa = studentGPA();

				cout << endl;
				cout << "Thank you. The data has been stored. \n\n";
				system("pause");
				system("CLS");

				FileOut(idnum, lname, fname, gpa);    //variable names
				break;

			case 2:
				findStudent();
				//findStudent();  
				break;
			case 3:
				system("CLS");
				Report();
				cout << endl;
				system("pause");
				system("CLS");
				break;

			case 4:
				return 0;

			default:
				cout << "Invalid Selection.  Start Over. \n\n";

			}//End of Switch opselect
			break;

		case 'N':
		case 'n':
			cout << endl;
			return 0;  // if N or n is typed, program exits

		default:
			cout << endl;
			cout << "Unknown response.  Please type Y or N.\n";
			cout << "Start over. \n\n";
		}//End of Switch answer

	} while ('Y' || 'y');     //end of do with while
}    //end of main

	 //all Fuctions below
//------------------------------------------------

 //function to get first name
void getfirstNAME(string &fname)
{
	do
	{			
		cout << "Enter First Name:               ";
		cin >> fname;
	} 
	while (fname.size() == 0 || fname.size() > 20);

	transform(fname.begin(), fname.end(), fname.begin(), tolower);  // transform string fname to all lowercase
	fname[0] = toupper(fname[0]);  // first letter of first name upper case only 
}


//function to get last name
void getlastNAME(string &lname)
{
	do
	{			
		cout << "Enter Last Name:                ";
		cin >> lname;
	} 
	while (lname.size() == 0 || lname.size() > 20);

	transform(lname.begin(), lname.end(), lname.begin(), tolower);  // transform string lname to all lowercase
	lname[0] = toupper(lname[0]); // first letter of string fname change to upper case only 
}


//function to get student ID number 
int idNUMBER()
{
	int idnumber = 0;
	do
	{
		cout << "Enter (3 digit) ID number:      ";
		cin >> idnumber;
	} 
	while (idnumber < 100 || idnumber > 999);

	return idnumber;
}


//function to get GPA 
float studentGPA()
{
	float studentGPA = 0;
	do
	{			
		cout << "Enter the Student's GPA:        ";
		cin >> studentGPA;
	} 
	while (studentGPA < 0.01 || studentGPA > 4.00);

	return studentGPA;
}


//fuction to file out
void FileOut(int idnum, string lname, string fname, float gpa)  //variable names not fuction names.
{
	ofstream outFile;
	outFile.open("INPUTSTUDENTS1.dat", ios::app);
	if (outFile.is_open())
	{
		outFile << idnum << '#' << lname << '#' << fname << '#' << fixed << setprecision(2) << gpa << endl;
	}
	else
	{
		cout << "File could not be opened." << endl;
	}
	outFile.close();
}

//infile 
void Report()
{
	int idnum = 0;
	string lname = " ";
	string fname = " ";
	float gpa = 0.00;

	ifstream inFile;
	inFile.open("INPUTSTUDENTS1.dat", ios::in);
	if (inFile.is_open())
	{
		cout << left << setfill(' ') << setw(15) << "ID" << setfill(' ') << setw(20) << "LAST" << setfill(' ') << setw(20) << "FIRST" << setfill(' ') << setw(5) << "GPA" << endl;
		cout <<	left << setfill(' ') << setw(15) << "  " << setfill(' ') << setw(20) << "NAME" << setfill(' ') << setw(20) << "NAME " << endl;

		// reads first ID
		inFile >> idnum;
		while (!inFile.eof())
		{
			inFile.ignore(1);
			getline(inFile, lname, '#');
			getline(inFile, fname, '#');
			inFile >> gpa;
			inFile.ignore(1);  //ignores endl ,  no extra #
			cout <<  left << setfill(' ') << setw(15) <<  idnum << setfill(' ') << setw(20) << lname << setfill(' ') << setw(20) << fname << setfill (' ') << setw(5) << fixed << setprecision(2) << gpa << endl;
			//reread ID 
			inFile >> idnum;
		}
	}
	else
	{
		cout << "File not opened" << endl;
	}

	inFile.close();

}  //end of voidReport infile function


// find student
void findStudent()
{
	int idnum = 0;
	string lname = " ";
	string fname = " ";
	float gpa = 0.00;
	int x = 0;
	int i = 0;
	MemberInfo ArrayName[NUMEL] = { 0,"","",0.00 };//declares an array of strings and brings values to null
	int location = 0;

	ifstream inFile;
	inFile.open("INPUTSTUDENTS1.dat", ios::in);
	if (inFile.is_open())
	{
		inFile >> ArrayName[x].idnum;
		while (x < NUMEL && !inFile.eof())
		{
			inFile.ignore(1);
			getline(inFile, lname, '#');
			ArrayName[x].lname = lname;
			getline(inFile, ArrayName[x].fname, '#');
			inFile >> ArrayName[x].gpa;
			inFile.ignore(1);  //ignores endl only 1 since no extra |# at end
			x++;
			inFile >> ArrayName[x].idnum;
		}
	}
	else
	{
		cout << "File not opened" << endl;
	}

	inFile.close();
	bubbleSort(ArrayName, x);
	cout << "\nThe sorted list, in ascending order by ID number is:\n";
	for (i = 0; i < x; ++i)
		cout << " " << ArrayName[i].idnum << " " << ArrayName[i].lname << " " << ArrayName[i].fname << endl;

	//search for the member
	cin.ignore(1);
	cout << "\nEnter Student ID to locate: ";
	cin >> idnum;
	cout << endl << endl;
	system("CLS");
	
	location = binarySearch(ArrayName, x, idnum);
	if (location > -1)
		cout << "The Student was found." << endl << endl <<
		        "ID:          " << ArrayName[location].idnum << endl <<
		        "Last Name:   " << ArrayName[location].lname << endl <<
		        "First Name:  " << ArrayName[location].fname << endl <<
		        "GPA:         " << fixed << setprecision(2) << ArrayName[location].gpa << endl << endl;
	else
		cout << "The Student ID was not located. \n\n";

	if (ArrayName[location].gpa > 3.65 &&  ArrayName[location].gpa < 4.01)
		cout << ArrayName[location].fname << " " << ArrayName[location].lname << " is on the Dean's List." << endl << endl;

	if (ArrayName[location].gpa > 2.00 &&  ArrayName[location].gpa < 3.66)
		cout << ArrayName[location].fname << " " << ArrayName[location].lname << " is an average student." << endl << endl;
	
	if (ArrayName[location].gpa > 0.01 &&  ArrayName[location].gpa < 2.00)
		cout << ArrayName[location].fname << " " << ArrayName[location].lname << " is on Academic Probation." << endl << endl;

	system("pause");
	system("cls");
}

void bubbleSort(MemberInfo StringData[], int numel)
{
	int i, j = 0;
	//	MemberInfo holdString = { 0,""};
	MemberInfo holdString = { 0,"","",0.00 };

	for (i = 0; i < (numel - 1); i++)
	{
		for (j = 1; j < numel; j++)
		{
			if (StringData[j].idnum < StringData[j - 1].idnum)
			{									
				holdString = StringData[j];
				StringData[j] = StringData[j - 1];
				StringData[j - 1] = holdString;
			}
		}
	}
}

int binarySearch(MemberInfo StringData[], int size, int key)
{
	int left = 0;
	int right = 0;
	int midpt = 0;

	right = size - 1;
	while (left <= right)
	{
		midpt = (int)((left + right) / 2);
		if (key == StringData[midpt].idnum)
		{
			return midpt;
		}
		else if (key > StringData[midpt].idnum)
			left = midpt + 1;
		else
			right = midpt - 1;
	}
	return -1;
}