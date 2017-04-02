// Ernestoi Murillo Functions Example - displays the average of three numbers

#include <iostream>
using namespace std;

//function prototypes
void getTestScores(float &, float &, float &);
float calcAverage(float, float, float);
void displayAverage(float);

// driver
int main()
{
	float score1  = 0.0;
	float score2  = 0.0;
	float score3  = 0.0;
	float average = 0.0;

	//enter scores
	getTestScores(score1, score2, score3);

	//calculate average
	average = calcAverage(score1, score2, score3);
	
	//display average
	displayAverage(average);

	system("pause");
	//return 0;
}	//end of main function

//*****program-defined functions*****
//Enter 3 test scores
void getTestScores(float &s1, float &s2, float &s3)
{
	cout << "Enter score 1: ";
	cin >> s1;
	cout << "Enter score 2: ";
	cin >> s2;
	cout << "Enter score 3: ";
	cin >> s3;
}	//end of getTestScores function

//calculate average 
float calcAverage(float s1, float s2, float s3)
{
	return (s1 + s2 + s3) / 3;
}	//end of calcAverage function

//print out the average
void displayAverage(float avg)
{
	cout << fixed;
	cout.precision(1);
	cout << "Average: " << avg << endl;
}	//end of displayAverage function
