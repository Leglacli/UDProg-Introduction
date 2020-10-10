/* Drill 5 */
#include "std_lib_facilities.h"

void codeNumber(int number);

int main()
{
	try
	{
		cout << "Drill5!\n";

		for (int i = 1; i <= 25; i++)
		{
			cout << "Code number: " << i << endl;
			codeNumber(i);
		}
		keep_window_open();
		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...)
	{
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}
void codeNumber(int number)
{
	switch(number)
	{
	case 1:
		//Cout << "Success!\n";
		cout << "Success!\n";
		break;
	case 2:
		//cout << "Success!\n;
		cout << "Success!\n";
		break;
	case 3:
		//cout <<" Success"<< !\n"
		cout << "Success!\n";
		break;
	case 4:
		//cout <<success<< endl;
		cout << "Success" << endl;
		break;
	case 5:
	{
		/*
		string res = 7;
		vector<int> v(10);
		v[5] = res;
		cout << "Success!\n";
		*/

		int res = 7;
		vector<int> v(10);
		v[5] = res;
		cout << "Success!\n";
		break;
	}
	case 6:
	{
		/*
		vector<int> v(10);
		v(5) = 7;
		if (v(5) != 7)
			cout << "Success!\n";
		*/

		vector<int> v(10);
		v[5] = 7;
		if (v[5] == 7)
			cout << "Success!\n";
		break;
	}
	case 7:
	{
		/*
		if (cond)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		*/

		bool cond = true;
		if (cond)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		break;
	}
	case 8:
	{
		/*
		bool c = false;
		if (c)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		*/

		bool c = false;
		if (c)
			cout << "Fail!\n";
		else
			cout << "Success!\n";
		break;
	}
	case 9:
	{
		/*
		string s = "ape";
		boo c = "fool" < s;
		if (c)
			cout << "Success!\n";
		*/

		string s = "ape";
		bool c = "fool" < s;
		if (!c)
			cout << "Success!\n";
		break;
	}
	case 10:
	{
		/*
		string s = "ape";
		if (s == "fool")
			cout << "Success!\n";
		*/

		string s = "ape";
		if (s != "fool")
			cout << "Success!\n";
		break;
	}
	case 11:
	{
		/*
		string s = "ape";
		if (s == "fool")
			cout < "Success!\n";
		*/

		string s = "ape";
		if (s != "fool")
			cout << "Success!\n";
		break;
	}
	case 12:
	{
		/*
		string s = " ape " ;
		if (s+ " fool " ) 
			cout < " Success!\n ";
		*/
	
		string s = " ape ";
		if (s != " fool ")
			cout << "Success!\n";
		break;
	}
	case 13:
	{
		/*
		vector<char> v(5); 
		for (int i=0; 0<v.size(); ++i) ; 
			cout << " Success!\n " ;
		*/

		vector<char> v(5);
		for (int i = 0; i < v.size(); ++i)
			cout << "Success!\n";
		break;
	}
	case 14:
	{
		/*
		vector<char> v(5);
		for (int i=0; i<=v.size(); ++i) ; 
		cout << " Success!\n " ; 
		*/

		vector<char> v(5);
		for (int i = 0; i < v.size(); ++i)
			cout << "Success!\n";
		break;
	}
	case 15:
	{
		/*
		string s = " Success!\n " ; 
		for (int i=0; i<6; ++i) 
			cout << s[i]; 
		*/

		string s = "Success!\n";
		for (int i = 0; i < 9; ++i)
			cout << s[i];
		break;
	}
	case 16:
		/*
		if (true) then 
			cout << " Success!\n " ; 
		else 
			cout << " Fail!\n " ; 
		*/

		if (true)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		break;
	case 17:
	{
		/*
		int x = 2000; 
		char c = x; 
		if (c==2000) 
			cout << " Success!\n " ; 
		*/
	
		int x = 2000;
		int c = x;
		if (c == 2000)
			cout << "Success!\n";
		break;
	}
	case 18:
	{
		/*
		string s = " Success!\n " ; 
		for (int i=0; i<10; ++i) 
			cout << s[i]; 
		*/

		string s = "Success!\n";
		for (int i = 0; i < s.size(); ++i)
			cout << s[i];
		break;
	}
	case 19:
	{
		/*
		vector v(5); 
		for (int i=0; i<=v.size(); ++i) ; 
			cout << " Success!\n " ; 
		*/

		vector<int> v(5);
		for (int i = 0; i <= v.size(); ++i)
			cout << "Success!\n";
		break;
	}
	case 20:
	{
		/*
		int i=0; 
		int j = 9;
		while (i<10) ++j; 
		if (j<i) 
			cout << " Success!\n " ; 
		*/

		int i = 0;
		int j = 9;
		while (i < 10)
			++i;
		if (j < i)
			cout << "Success!\n";
		break;
	}
	case 21:
	{
		/*
		int x = 2; 
		double d = 5/(x – 2); 
		if (d==2*x+0.5) 
			cout << " Success!\n " ; 
		*/

		int x = 2;
		double d = 5.0/x + 2;
		if (d == 2 * x + 0.5)
			cout << "Success!\n";
		break;
	}
	case 22:
	{
		/*
		string<char> s = " Success!\n " ; 
		for (int i=0; i<=10; ++i) 
			cout << s[i]; 
		*/

		string s = "Success!\n";
		for (int i = 0; i <= 8; ++i)
			cout << s[i];
		break;
	}
	case 23:
	{
		/*
		int i=0; 
		while (i<10) 
			++j; 
		if (j<i) 
			cout << " Success!\n " ;
		*/

		int i = 0;
		int j = 9;
		while (i < 10)
			++i;
		if (j < i)
			cout << "Success!\n";
		break;
	}
	case 24:
	{
		/*
		int x = 4; 
		double d = 5/(x – 2); 
		if (d=2*x+0.5) 
			cout << " Success!\n " ; 
		*/

		int x = 4;
		double d = 5.0 / (x - 2);
		if (d = 2 / x + 0.5)
			cout << "Success!\n";
		break;
	}
	case 25:
		//cin << " Success!\n " ;

		cout << "Success!\n";
		break;
	default:
		cout << "Incorrect code number!\n";
		break;
	}
}

