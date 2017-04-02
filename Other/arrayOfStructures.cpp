// Ernesto Murillo - example of an array of structures
#include<iostream>
#include<string>
#include<iomanip>
#include <algorithm>
using namespace std;

// constants
const int NUMEL = 100;

struct Payroll
{	string name;
	float  hours;
	float  dollars;
}

// prototypes
void fillArray(Payroll [], int size, int& numberUsed);
void bubbleSort(Payroll [], int);
int binarySearch(Payroll [], int, string);

//driver
int main()
{
  // declare variables  
  Payroll employee[NUMEL];
  int numberUsed, i=0;
  string name=""; 
  int location = 0;

  fillArray(employee, NUMEL, numberUsed);

  bubbleSort(employee, numberUsed);

  cout << "\nThe sorted list, in ascending order, is:\n";
  for (i = 0; i < numberUsed; ++i)
  cout << "  " <<employee[i].name<<'\t'<<employee[i].hours<<'\t'<<employee[i].dollars<<'\n';

  cout << "\nEnter the name you are searching for: ";
  getline(cin,name);

  location = binarySearch(employee, numberUsed, name);
  if (location > -1)
    cout << "Employee: "<<employee[location].name<<"\tHours: "<<employee[location].hours<<"\tDollars: "
         <<employee[location].dollars<<endl;
	 
  else
    cout << "The employee was not found\n";
	cout << "the end\n";

	system("pause");
  //return 0;
}

// load Payroll records
void fillArray(Payroll p[], int size, int& numberUsed)
{
    cout << "Enter up to " << size << " employees.\n"
         << "Mark the end of the list with XX.\n";

    int index = 0;
    string next_name ="";
    cout<<"Name: ";
    getline(cin,next_name);
    transform(next_name.begin(), next_name.end(), next_name.begin(), toupper); 

    while ((next_name != "XX") && (index < size))
    {
        p[index].name = next_name;
      	cout<<"Hours: ";
	cin>>p[index].hours;
	cout<<"Dollars: ";
	cin>>p[index].dollars;

        index++;
        getline(cin,next_name);
        transform(next_name.begin(), next_name.end(), next_name.begin(), toupper);  
    }

    numberUsed = index;
}
//*****************************************************************


// Sort Payroll records
void bubbleSort(Payroll num[], int numberUsed)
{
  int i, j= 0;
  Payroll temp="";

  for ( i = 0; i < (numberUsed - 1); i++)
  {
    for(j = 1; j < numberUsed; j++)
    {
      if (num[j].name < num[j-1].name)
      {
	temp = num[j];
	num[j] = num[j-1];
	num[j-1] = temp;
      }// end if
    } // end for (inside)
  } // end for (outside)

}// end bubblesort function

// Search the payroll
int binarySearch(Payroll list[], int size, string key)
{
  int left, right, midpt = 0;

  right = size - 1;

  while (left <= right)
  {
    midpt = (int) ((left + right) / 2);
    if (key == list[midpt].name)
    {
      return midpt;
    }
    else if (key > list[midpt].name)
                  left = midpt + 1;
           else
                  right = midpt - 1;
  }
  return -1;
}
