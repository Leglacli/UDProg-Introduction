#include "std_lib_facilities.h"

void sayHello();

int main()
{
	sayHello();
	return 0;
}

void sayHello()
{
	//Printing out "Hello, World!".
	cout << "Hello, World!\n";

	//Keeping the window open until the user makes an input.
	keep_window_open();
}
