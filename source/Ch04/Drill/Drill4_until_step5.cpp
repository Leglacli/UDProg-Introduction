/*
Drill 4
1. Write a program that consists of a while-loop that (each time around the loop) reads in two ints
   and then prints them. Exit the program when a terminating '|' is entered.

2. Change the program to write out the smaller value is: followed by the 
   smaller of the numbers and the larger value is: followed by the larger value.

3. Augment the program so that it writes the line the numbers are equal (only) if they are equal.

4. Change the program so that it uses doubles instead of ints.

5. Change the program so that it writes out the numbers are 
   almost equal after writing out which is the larger and the smaller if the two numbers differ by less than 1.0/100.
*/

#include "std_lib_facilities.h"

const double difference = 1.0 / 100;
double min(double num1, double num2);
double max(double num1, double num2);
bool almost_equal(double num1, double num2);

void compare();

int main()
{
	compare();
	return 0;
}

//Deciding the smaller number
double min(double num1, double num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

//Deciding the larger number
double max(double num1, double num2)
{
	if (num1 >= num2)
		return num1;
	else
		return num2;
}

//Checking if almost equal
bool almost_equal(double num1, double num2)
{
	if (max(num1, num2) - min(num1, num2) < difference)
		return true;
	else
		return false;
}

void compare()
{
	double num1, num2;
	cout << "Type in 2 numbers (to stop type '|' )\n";

	while (cin >> num1 >> num2)
	{
		cout << "Your numbers are: " << num1 << " and " << num2 << endl;
		if (num1 == num2)
			cout << num1 << " and " << num2 << " are equal!\n";
		else
		{
			cout << min(num1, num2) << " is the smaller value!\n";
			cout << max(num1, num2) << " is the larger value!\n";
			if (almost_equal(num1, num2))
				cout << num1 << " and " << num2 << " are almost equal!\n";
		}
	}
}
