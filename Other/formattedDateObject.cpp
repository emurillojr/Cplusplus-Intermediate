// Ernesto Murillo  - displays a formatted date object
#include <iostream>
#include <string>

//using namespace std;
using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

class Date
{
	public:
		Date();
		void assignDate(string,string,string);
		string getDate(string);

	private:
		string month;
		string day;
		string year;
};

Date::Date()
{
	month = "";
	day = "";
	year = "";
}

void Date::assignDate(string m, string d, string y)
{
	month = m;
	day = d;
	year = y;
}

string Date::getDate(string separator)
{	
	return month + separator + day + separator + year;
}


int main()
{
	//create object
	Date dateObj;

	//declare variables
	string month     = "";
	string day       = "";
	string year      = "";
	string separator = "";

	//get month, day, year, and separator
	cout << "Month: ";
	getline(cin, month);
	cout << "Day: ";
	getline(cin, day);
	cout << "Year: ";
	getline(cin, year);
	cout << "Separator (/ or -): ";
	getline(cin, separator);

	//assign values to object
	dateObj.assignDate(month, day, year);
	//use object to get the formatted date
	cout << dateObj.getDate(separator) << endl;

	system("pause");
	//return 0;
} //end of main function
