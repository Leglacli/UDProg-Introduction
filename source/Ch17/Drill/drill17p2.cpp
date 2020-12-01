#include "std_lib_facilities.h"

int main()
{
	int x = 7;
	int* p1 = &x;

	cout << "Value of p1: " << p1 << " and value of the int it points to: " << *p1 << endl;

	int* p2 = new int[7];

	x = 1;
	for (int i = 0; i < 7; i++)
	{
		p2[i] = x;
		x *= 2;
	}

	cout << "The value of p2: " << p2 << endl;
	cout << "The values in the array: " << endl;

	for (int j = 0; j < 7; j++)
		cout << p2[j] << endl;

	int* p3 = p2;
	p1 = p2;
	p3 = p2;

	cout << "The value of p1 is: " << p1 << " and the value of the variable it points to: " << *p1 << endl;
	cout << "The value of p2 is: " << p2 << " and the value of the variable it points to: " << *p2 << endl;
	
	delete[] p2;

	p1 = new int[10]{ 1, 2, 4, 8, 16, 32, 128, 256, 512 };
	p2 = new int[10];

	for (int k = 0; k < 10; k++)
		p2[k] = p1[k];

	//vector

	vector<int> v1 { 1, 2, 4, 8, 16, 32, 128, 256, 512 };
	vector<int> v2 (10);
	v2 = v1;

}
