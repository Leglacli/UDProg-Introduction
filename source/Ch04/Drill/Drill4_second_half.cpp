//Drill 4 step 6-11
#include "std_lib_facilities.h"

const vector<string> units { "m", "cm", "in", "ft" };
const double cm_to_m = 0.01;
const double in_to_m = 0.0254;
const double ft_to_m = 0.3048;
bool acceptedUnit(string unit);
double convertToMeter(double num, string unit);

void convert();

int main()
{
	convert();
	return 0;
}

void convert()
{
	double num;
	double smallest = 0;
	double largest = 0;
	double sum = 0;
	double numInMeter = 0;
	vector<double> values;
	int numbersEntered = 0;
	string unit;

	cout << "Type in a number followed by an unit (accepted units are: cm, in, ft, m, to stop type '|' )\n";

	while (cin >> num >> unit)
	{
		if (acceptedUnit(unit))
		{
			numInMeter = convertToMeter(num, unit);
			numbersEntered++;
			if (numbersEntered == 1)
			{
				smallest = numInMeter;
				largest = numInMeter;
				cout << num << unit << " (" << numInMeter << "m) is the smallest and largest number so far!\n";
			}
			else if (num <= smallest)
			{
				smallest = num;
				cout << smallest << unit << " (" << numInMeter << "m) is the smallest so far!\n";
			}
			else if (num >= largest)
			{
				largest = num;
				cout << largest << unit << " (" << numInMeter << "m) is the largest so far!\n";
			}

			values.push_back(numInMeter);
			sum += numInMeter;
		}
		else
			cout << "Incorrect unit type, the accepted units are: cm, in, ft, m! \n";
	}

	cout << "The largest value is " << largest << " m\n";
	cout << "The smallest value is " << smallest << " m\n";
	cout << "Number of values entered: " << numbersEntered << '\n';
	cout << "Sum of all the values entered: " << sum << " m\n";

	cout << "List of values (sorted):\n";
	sort(values);
	for (double value : values)
		cout << value << " m\n";
}

bool acceptedUnit(string unit)
{
	bool isAccepted = false;

	//Checking if unit is in the accepted units
	for (string acceptedUnit : units)
		if (acceptedUnit == unit)
			isAccepted = true;

	return isAccepted;
}

//Converting to meter
double convertToMeter(double num, string unit)
{
	double numInMeter = 0;

	if (unit == "cm")
		numInMeter = num * cm_to_m;
	else if (unit == "in")
		numInMeter = num * in_to_m;
	else if (unit == "ft")
		numInMeter = num * ft_to_m;
	else
		numInMeter = num;

	return numInMeter;
}
