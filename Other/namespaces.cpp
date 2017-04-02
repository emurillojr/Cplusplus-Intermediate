// Ernesto Murillo - namespaces

#include <iostream>
using namespace std;

namespace Hello
{ void message(); }

namespace GoodBye
{ void message();}

void message() { cout<<"Global message.\n";};

int main()
{
	message();
	{
	   using GoodBye::message;
		{ 
			using Hello::message;
			message();
			GoodBye::message();
			Hello::message();
		 }
	   message();
	}
	message();

	system("pause");
	//return 0;
}

namespace Hello
	{
		void message()
		{cout<<"Hello.\n"; }
	}

namespace GoodBye
{
	void message()
	{cout<<"Good Bye.\n";}
}
