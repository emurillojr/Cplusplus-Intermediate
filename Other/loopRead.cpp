// Ernesto Murillo - example of loop read

#include <iostream>;
#include <string>;
#include <fstream>;
using namespace std;

int main()
{ 
	string name	 = "";
	int number	 = 0;
	char tech    = ' ';

	ifstream inFile;
	inFile.open("TLDTSTWRT.dat", ios::in);
	if(inFile.is_open())
	{
		getline(inFile,name,'#');
		while(!inFile.eof())
		{
			inFile>>number;
			inFile.ignore(1);
			inFile>>tech;
			inFile.ignore(2);
			cout<<"name is "<<name<<"\t number is "<<number<<"\t tech is "<<tech<<"\n\n";
			getline(inFile,name, '#');
		}
	}
	else
	{ cout<<"File not opened"<<endl;}
	inFile.close();

	system("pause");
	//return 0;
}
