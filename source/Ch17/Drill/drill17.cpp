#include "std_lib_facilities.h"

/*
ostream& print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; i++)
		os << a[i] << endl;
	return os;
}
*/

ostream& print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; i++)
		os << a[i] << endl;
	return os;
}

ostream& print_vector(ostream& os, vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		os << v[i] << endl;
	return os;
}




int main()
{
	/*
	//10 int
	int* array10 = new int[10];
	for (int i = 0; i < 10; i++)
		array10[i] = 100 + i; 
	print_array10(cout, array10, 10);

	//11 int
	int* array11 = new int[11];
	for (int i = 0; i < 11; i++)
		array10[i] = 100 + i;
	print_array10(cout, array10, 11);
	*/

	//20 int
	/*
	int* array20 = new int[20];
	for (int i = 0; i < 20; i++)
		array20[i] = 100 + i;
	print_array(cout, array20, 20);
	delete[] array20;
	*/

	vector<int> v10(10);
	for (int i = 0; i < v10.size(); i++)
		v10[i] = 100 + i;
	print_vector(cout, v10);
}