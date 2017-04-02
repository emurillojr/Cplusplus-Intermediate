// Ernesto Murillo - calculate grade using do while loop

#include <iostream>
using namespace std;
const int HIGHGRADE = 100;

int main()
{
  //declare variables  
  float grade = 0.0;
  float total = 0.0;
  float avg=0.0;
  int cnt=0;

  //input data
  cout << "\nTo stop entering grades, type in any number"<< " greater than 100.\n" << endl;
  
  //loop till grade out of range
  do
  {
    total = total + grade;
    cout << "Enter a grade: ";
    cin  >> grade;
    cnt++;
  }
  while (grade <= HIGHGRADE);

  //output average
  cout << "\nThe total of the grades is " << total << endl;
  cout << "\nThe average grade is " << total/(cnt-1) << endl;

  system("pause");
  //return 0;
}
