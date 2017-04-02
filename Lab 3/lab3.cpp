// Ernesto Murillo - Lab 3

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime> 
#include<cstdlib> 
#include<algorithm>
using namespace std;

//function prototype
void getfirstNAME(string&);  // first name
void getlastNAME(string&);  //last name
void studentDATA();  //case 1 entering student data function
void FileOut(string, string, int);
void Report(); // infile data 
int testSCORES();  //test scores


int main()
{
	// declare variables
	int opselect = 0;
	string fname = " ";
	string lname = " ";
	int tscore = 0;
	int totalstudents = 0;
	string grade = " ";
	double totalscores = 0;
	double totalAverage = 0;

	do 
	{
		// Program menu
		cout << "Welcome to the NEIT Test Grade Analyzer. \n\n";
		cout << "Please select an option below. \n\n";
		cout << "1- Enter Student Data \n";
		cout << "2- Class Grade Report. \n";
		cout << "3- Exit \n\n";
		cout << "Make a selection: ";
		cin >> opselect;
		cout << endl;


		switch (opselect)
		{
			//Enter Student Data
			case 1:
			getfirstNAME(fname);
			totalstudents++;
			getlastNAME(lname);
			tscore = testSCORES();
			cout << endl;
			cout << "Thank you. The data has been stored. \n\n";
			system("pause");
			system("CLS");
						
			FileOut(fname, lname, tscore);
			break;
						
			case 2:
			Report();   
			cout << endl;
			system("pause");
			break;

			case 3:
			return 0;

			default:
			cout << "Invalid Selection";
			
		}//End of Switch

	} while (1);  //end of do with while


}//end of main



//all Fuctions below
 
 //function to get first name
void getfirstNAME(string &fname)
{
	do
	{
	cout << "Enter First Name: ";
	cin >>fname;
	
	} while (fname.size() == 0 || fname.size() > 20);
	
	transform(fname.begin(), fname.end(), fname.begin(), tolower);  // first name all lower case transform
	fname[0] = toupper(fname[0]);  // first letter of first name upper case only 
}


//function to get last name
void getlastNAME(string &lname)
{
	do
	{
	cout << "Enter Last Name: ";
	cin >> lname;
	
	} while (lname.size() == 0 || lname.size() > 20);
	
	transform(lname.begin(), lname.end(), lname.begin(), tolower);  // last name all lower case transform
	lname[0] = toupper(lname[0]); // first letter of last name upper case only 
}


//function to get test score
int testSCORES()
{
	int tscore = 0;
	do 
	{
	cout << "Enter Test Score: ";
	cin >> tscore;
	} 
	while (tscore < 0 || tscore > 100);

	return tscore;
}


//fuction to file out
void FileOut(string fname, string lname, int tscore)  //variable names not fuction names.
{
	ofstream outFile;
	outFile.open("students.dat", ios::app);
	if (outFile.is_open())
	{
	outFile << fname << '#' << lname << '#' << tscore << '#' << endl;
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
	int opselect = 0;
	string fname = " ";
	string lname = " ";
	int tscore = 0;
	int totalstudents = 0;
	string grade = " ";
	int totalAs = 0;
	int totalBs = 0;
	int totalCs = 0;
	int totalDs = 0;
	int totalFs = 0;
	double totalscores = 0;
	double totalAverage = 0;

	ifstream inFile;
	inFile.open("students.dat", ios::in);
	if (inFile.is_open())
	{
	cout << left << setfill(' ') << setw(20) << "FIRST NAME" << " " << setw(20) << "LAST NAME" << " " << setw(4) << "TEST SCORE" << endl;

	// reads first string  not infile
	getline(inFile, fname, '#');

		while (!inFile.eof())
		{
		getline(inFile, lname, '#');
		inFile >> tscore;
		totalstudents++;

			if (tscore >= 90 && tscore <= 100)
			{
				totalAs++;
			}
			if (tscore >= 80 && tscore <= 89)
			{
				totalBs++;
			}
			if (tscore >= 70 && tscore <= 79)
			{
				totalCs++;
			}
			if (tscore >= 60 && tscore <= 69)
			{
				totalDs++;
			}
			if (tscore < 60)
			{
				totalFs++;
			}
			totalscores = totalscores + tscore;
			totalAverage = totalscores / totalstudents;

		inFile.ignore(2);  //ignores # and endl

		cout << left << setfill(' ') << setw(20) << fname << " " << setw(20) << lname << " " << setw(4) << tscore << endl;
		//reread first string again
		getline(inFile, fname, '#');
		}

	cout << "Total Students Processed:          " << totalstudents << endl;
	cout << "Total Students who got an A:       " << totalAs << endl;
	cout << "Total Students who got an B:       " << totalBs << endl;
	cout << "Total Students who got an C:       " << totalCs << endl;
	cout << "Total Students who got an D:       " << totalDs << endl;
	cout << "Total Students who got an F:       " << totalFs << endl;
	cout << "Average Score for the class:       " << totalAverage << endl;
	cout << endl;
	} 
	else
	{
	cout << "File not opened" << endl;
	}

	inFile.close();
	
}  //end of voidReport infile function
