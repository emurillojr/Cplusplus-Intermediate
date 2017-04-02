// Ernesto Murillo - bubble sort example

#include <iostream>;
using namespace std;

const int NUMEL = 5;
int bubbleSort(int [], int);

int main()
{
  int nums[NUMEL] = {22,5,67,98,45};
  int i, moves;
  moves = bubbleSort(nums, NUMEL);
  cout << "\nThe sorted list, in ascending order, is:\n";
  for (i = 0; i < NUMEL; ++i)
  cout << "  " <<nums[i];
  cout << endl << moves << " were made to sort this list\n";

  system("pause");
  //return 0;
}


int bubbleSort(int num[], int numel)
{
  int i, j, grade, moves = 0;

  for ( i = 0; i < (numel - 1); i++)
  {
    for(j = 1; j < numel; j++)
    {
      if (num[j] < num[j-1])
      {
	grade = num[j];
	num[j] = num[j-1];
	num[j-1] = grade;
	moves++;
      }
    }
  }

  return moves;
}
