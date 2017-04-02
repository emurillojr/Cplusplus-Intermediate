//Originally written by Walter Savitch
//Modified by Ernesto Murillo - Program to demonstrate the Date structure type.

#include<iostream>
#include<iomanip> 
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

// Structure used to store date information:
struct Date
{
    int month;
    int day;
    int year;
};

// prototypes
void getDate(Date& theDate);

int main( )
{
    // declare variables
    string name="";
    Date dob={01, 01, 1900};

    //Enter Patient Name
    cout << "Enter patient name:\t";
    getline(cin,name,'\n');

    //Enter Date of Birth
    getDate(dob);

    //Output patient information
    cout << "Name: " <<name<<"   DOB "<<dob.month<<'/'<<dob.day<<'/'<<dob.year<<endl;
      
	system("pause");
    //return 0;
}//End main

void getDate(Date& theDate)
{
    cout << "Enter month: ";
    cin >> theDate.month;
    cout << "Enter day: ";
    cin >> theDate.day;
    cout << "Enter year: ";
    cin >> theDate.year;
}
