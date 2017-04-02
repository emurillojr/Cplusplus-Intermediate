// Ernesto Murillo  - Assignment 1

#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;

int yearsActive();
void getFirstName(string&);
void getLastName(string&);
void newMembership();
void getMemberType(string&);
void reportA(int, string, string, string);
void report2(int);
void report3(int);
void report4(int);
int gettotaldues();

int main()
{
	int opselect = 0;
	int totalmembers = 0;
	int totalduesall = 0;
	double totalFDUES = 0;
	double totalIDUES = 0;
	int duesF1 = 0;
	int totalFdues = 0;
	int years = 0;
	string mType=" ";
	string fname;
	string lname;
	double mDuesF1 = 0;
	double mDuesF2 = 0;
	double mDuesI1 = 0;
	double mDuesI2 = 0;
	double totalfduesall=0;
	double totaliduesall=0;

	do {
		// Menu
		cout << "Welcome to the Wannamoisett Country Club.\n";
		cout << "Press 1 for Membership Dues inquiry.\n";
		cout << "Press 2 for Summary Totals Page. \n";
		cout << "Press 3 to EXIT. \n";
		cin >> opselect;

		switch (opselect)
		{

		//New Memeber
		case 1:
		//Enter First Name
		getFirstName(fname);
		//Enter Last Name
		getLastName(lname);
		// Member Type
		getMemberType(mType);
		// Years Active
		years = yearsActive();
		//	newMembership();
		totalmembers++;
		cout << endl;

		if (mType == "F" && years <= 6 || mType == "f" && years <= 6)
		{
		mDuesF1 = 1600;
		cout << fname << " " << lname << " is an " << mType << " membership" << " and annual dues are $" <<mDuesF1<<".";
		cout<< endl;
		cout<< endl;
		totalFDUES = totalFDUES +1600;
		}

		if (mType == "F" && years >= 7 || mType == "f" && years >= 7)
		{
		mDuesF2 = 1200;
		cout << fname << " " << lname << " is an " << mType << " membership" << " and annual dues are $" <<mDuesF2<<".";
		cout<< endl;
		cout<< endl;
		totalFDUES = totalFDUES +1200;
		}

		if (mType == "I" && years <= 6 || mType == "i" && years <= 6)
		{
		mDuesI1 = 1100;
		cout << fname << " " << lname << " is an " << mType << " membership" << " and annual dues are $" <<mDuesI1<<".";
		cout<< endl;
		cout<< endl;
		totalIDUES = totalIDUES +1100;
		}

		if (mType == "I" && years >= 7 || mType == "i" && years >= 7)
		{
		mDuesI2 = 800;
		cout << fname << " " << lname << " is an " << mType << " membership" << " and annual dues are $" <<mDuesI2<<".";
		cout<< endl;
		cout<< endl;
		totalIDUES = totalIDUES +800;
		}
		break;

		case 2:
			report2(totalmembers);
			cout << endl;
			report3(totalFDUES);
			cout << endl;
			report4(totalIDUES);
			cout << endl;
			cout << endl;
			break;
		case 3:
			return 0;
		default:
			cout << "\n";
			cout << "Invaild Selection\n";
			cout << "Must Enter 1, 2, or 3";
			cout <<endl;
			cout <<endl;
		}
		} while (1);
}  //end of main

void getFirstName(string &fname)
{
	do
	{
		cout << "Enter First Name (No more than 10 characters): ";
		cin >> fname;
	} 
	while (fname.size() == 0 || fname.size() > 10);
	fname[0] = toupper(fname[0]);
}

void getLastName(string &lname)
{
	do
	{
		cout << "Enter Last Name (No more than 15 characters): ";
		cin >> lname;
	} 
	while (lname.size() == 0 || lname.size() > 15);
	lname[0] = toupper(lname[0]);
}

void getMemberType(string &mType)
{
	do
	{
		cout << "Enter type of membership (F for Family or I for Individual): ";
		cin >> mType;
	}
	while (mType != "F" && mType != "f" && mType != "I" && mType != "i");
	mType[0] = toupper(mType[0]);

}

int yearsActive()
{
	int years = 0;
	do
	{
		cout << "Enter years active at the club: (1-100) ";
		cin >> years;
	} 
	while (years < 1 || years>100);
	return years;
}

void report2(int totalmembers)
{
	cout << "Total Number of Records Processed:       " << totalmembers << ".";
	cout << endl;
}

void report3(int totalFDUES)
{
	cout << "Total Family Dues:                      $" << totalFDUES << ".";
	cout << endl;
}

void report4(int totalIDUES)
{
	cout << "Total Individual Dues:                  $" << totalIDUES << ".";
	cout << endl;
}
