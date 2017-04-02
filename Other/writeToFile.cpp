// Ernesto Murillo - example of writes to a file

 #include<iostream>
 #include<fstream>
 #include<string> 
 #include<algorithm> 
 
 using namespace std;
 int main()
 {
	string name = "";
	int number  = 0;
	char tech = ' ';

	ofstream outFile;
	outFile.open("TLDAPPWRT.dat",ios::app);
	if (outFile.is_open())
	{
		//enter data 
	do 
	{
	cout<<"Enter student name: (x to stop)"<<endl;
	getline(cin, name);
	transform(name.begin(), name.end(), name.begin(), toupper); 

	if(name == "X")
		{break;}
	do 
		{
			cout<<"enter student number (5 digits)"<<endl;
			cin>>number;
		}	
		
	while(number>=10000 && number >99999);
	
	do 
		{
			cout<<"Enter student tech (1 char - a = aut, c = cis, n = net):  "<<endl;
			cin>>tech; 
			tech=tolower(tech);
			if (tech == 'a' || tech == 'c' || tech == 'n') 
			{ break; }
		}	

	while(1); 
		
	outFile<<name<<'#'<<number<<'#'<<tech<<'#'<<endl;
	cin.ignore(1);		
		
	}
	while (name !="X");

	}
	else
	cout<<"File could not be opened."<<endl;
	outFile.close();
	
	return 0;
	}
