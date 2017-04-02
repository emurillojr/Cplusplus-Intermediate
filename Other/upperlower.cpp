// Ernesto Murillo - make a name upper/lowercase

#include<iostream>;
#include<string>;
#include<algorithm>;
#include<iomanip>;
using namespace std;

int main()
{
	string name  ="";
	int position =0;
	string hyphens;

	// enter name
	cout<<"enter name ";
	getline(cin, name);

	// name all lower case
	transform(name.begin(), name.end(), name.begin(), tolower);

	// first letter of name upper case
	name [0] = toupper(name[0]);
	
	// find first space - now go to next character 
	position=name.find(" ", 0)+1;
	
	// second part of 2 part name - make upper case.
	name [position] = toupper(name [position]);

	position = name.size();
	hyphens.assign(position,'-');

	cout<<"\t\t"<<name<<endl;
	cout<<"\t\t"<<hyphens<<endl;


	cout<<left<<setw(25)<<setfill(' ')<<"NAME"<<endl;
	cout<<left<<setw(25)<<setfill(' ')<<hyphens<<"\n\n";
	cout<<left<<setw(25)<<setfill(' ')<<name<<endl;

	system("pause");
	//return 0;
}	//end main program   




