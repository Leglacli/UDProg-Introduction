#include "std_lib_facilities.h"

//Points for test: (1,4)(4,2)(7,2)(9,9)(4,1)(5,2)(3,7)

struct Point
{
	int x;
	int y;
};

istream& operator>>(istream& is, Point& p)
{
	char ch1;
	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	char ch3;
	int xx;
	int yy;

	is >> xx >> ch2 >> yy >> ch3;
	if (!is || ch3 != ')')
	{
		if (is.eof())
			return is;
		error("bad point");
	}
	p.x = xx;
	p.y = yy;
	return is;
}

ostream& operator<<(ostream& os, Point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}

void fill_from_file(vector<Point>& points, string& name)
{
	ifstream ist{ name };
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	if (!ist)
		error("Can't open input file ", name);
	for (Point p; ist >> p; )
		points.push_back(p);
}

int main()
try
{
	//Ask the user for 7 points
	vector<Point> original_points;
	cout << "Enter 7 points of x,y: " << endl;

	while (original_points.size() < 7)
	{
		Point p;
		cin >> p;
		original_points.push_back(p);
	}

	//Print out the points
	cout << endl;
	cout << "Original points: ";
	for (Point p : original_points)
		cout << p;
	cout << endl;

	//Write the points to file
	string file_name = "mydata.txt";
	ofstream ost{ file_name };
	if (!ost)
		error("Can't open file: ", file_name);

	for (Point p : original_points)
		ost << p;
	ost.close();


	//Read back from file
	vector<Point> processed_points;
	fill_from_file(processed_points, file_name);

	cout << "Processes points: ";
	for (Point p : processed_points)
		cout << p;
	cout << endl;

	//Check if original and processed are the same
	if (original_points.size() != processed_points.size())
		cout << "Error, size is not equal!" << endl;
}
catch(exception& e)
{
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch(...)
{
	cerr << "Unknown exception" << endl;
	return 2;
}
