#include "my.h"
#include "std_lib_facilities.h"

void print_foo()
{
	cout << "The value of foo is: " << foo << endl;
}

void print(int i)
{
	cout << "The value of the integer is: " << i << endl;
}

void swap_v(int a, int b)
{
	cout << "Swapping " << a << " with " << b << endl;
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	cout << "Swapping " << a << " with " << b << endl;
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/* Can't because const
void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
*/