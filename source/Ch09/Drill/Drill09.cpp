#include "std_lib_facilities.h"

//9.4.1
/*
struct Date
{
	int y;
	int m;
	int d;
};

void init_date(Date& date, int y, int m, int d)
{
	if (m < 1 || m > 12)
		error("Invalid month");
	if (d < 1 || d > 31)
		error("Invalid day");

	date.y = y;
	date.m = m;
	date.d = d;
}

void add_day(Date& date, int day)
{
	date.d += day;
	if (date.d > 31)
		date.d %= 31;
}

ostream& operator<<(ostream& os, Date& date)
{
	return os << date.y << '.' << date.m << '.' << date.d;
}

int main()
{
	Date today;
	init_date(today, 1978, 6, 25);
	Date tomorrow = today;
	add_day(tomorrow, 1);

	cout << "The date today is: " << today << endl;
	cout << "The date tomorrow will be: " << tomorrow << endl;

	
	//Date invalid_date;
	//init_date(invalid_date, 2004, 13, -5);
	
}
*/

//9.4.2
/*
struct Date 
{
	int y, m, d;
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int year, int month, int day)
	:y{ year }, m{ month }, d{ day }
{
	if (m < 1 || m > 12)
		error("Invalid month");
	if (d < 1 || d > 31)
		error("Invalid day");
}

void Date::add_day(int day)
{
	d += day;
	if (d > 31)
		d %= 31;
}

ostream& operator<<(ostream& os, Date& date)
{
	return os << date.y << '.' << date.m << '.' << date.d;
}

int main()
try
{
	Date today(1978, 6, 25);
	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << "The date today is: " << today << endl;
	cout << "The date tomorrow will be: " << tomorrow << endl;

	//Date invalid_date(2004, 13, -5);
}
catch (exception& e)
{
	cerr << e.what() << endl;
	return 1;
}
catch (...)
{
	cerr << "Unknown exception" << endl;
	return 2;
}
*/

//9.4.3
/*
class Date
{
private:
	int y, m, d;

public:
	Date(int y, int m, int d);
	void add_day(int day);
	int year() { return y; };
	int month() { return m; };
	int day() { return d; };
};

Date::Date(int year, int month, int day)
	:y{ year }, m{ month }, d{ day }
{
	if (m < 1 || m > 12)
		error("Invalid month");
	if (d < 1 || d > 31)
		error("Invalid day");
}

void Date::add_day(int day)
{
	d += day;
	if (d > 31)
		d %= 31;
}

ostream& operator<<(ostream& os, Date& date)
{
	return os << date.year() << '.' << date.month() << '.' << date.day();
}

int main()
try
{
	Date today(1978, 6, 25);
	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << "The date today is: " << today << endl;
	cout << "The date tomorrow will be: " << tomorrow << endl;

	//Date invalid_date(2004, 13, -5);
}
catch(exception& e)
{
	cerr << e.what() << endl;
	return 1;
}
catch (...)
{
	cerr << "Unknown exception" << endl;
	return 2;
}
*/

//9.7.1
/*
enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> months { "January", "February", "March", "April", "May",
							"June", "July", "August", "September", "October",
							"November", "December" };

class Date
{
private:
	int y;
	Month m;
	int d;
	
public:
	Date(int y, Month m, int d);
	void add_day(int day);
	int year() { return y; };
	Month month() { return m; };
	int day() { return d; };
};

Date::Date(int year, Month month, int day)
	:y{ year }, m{ month }, d{ day }
{
	if (d < 1 || 31 < d)
		error("Invalid day");
}

void Date::add_day(int day)
{
	d += day;
	if (d > 31)
		d %= 31;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

ostream& operator<<(ostream& os, Date& date)
{
	return os << date.year() << '.' << date.month() << '.' << date.day();
}

int main()
try
{
	Date today(1978, Month::jun, 25);
	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << "The date today is: " << today << endl;
	cout << "The date tomorrow will be: " << tomorrow << endl;

	//Date invalid_date(2004, 13, -5);

}
catch (exception& e)
{
	cerr << e.what() << endl;
	return 1;
}
catch (...)
{
	cerr << "Unknown exception" << endl;
	return 2;
}
*/

//9.7.4
enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> months{ "January", "February", "March", "April", "May",
							"June", "July", "August", "September", "October",
							"November", "December" };

class Date
{
private:
	int y;
	Month m;
	int d;

public:
	Date(int y, Month m, int d);
	void add_day(int day);
	int year() const { return y; };
	Month month() const { return m; };
	int day() const { return d; };
};

Date::Date(int year, Month month, int day)
	:y{ year }, m{ month }, d{ day }
{
	if (d < 1 || 31 < d)
		error("Invalid day");
}

void Date::add_day(int day)
{
	d += day;
	if (d > 31)
		d %= 31;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

ostream& operator<<(ostream& os, const Date& date)
{
	return os << date.year() << '.' << date.month() << '.' << date.day();
}

int main()
try
{
	Date today(1978, Month::jun, 25);
	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << "The date today is: " << today << endl;
	cout << "The date tomorrow will be: " << tomorrow << endl;

	//Date invalid_date(2004, 13, -5);

}
catch (exception& e)
{
	cerr << e.what() << endl;
	return 1;
}
catch (...)
{
	cerr << "Unknown exception" << endl;
	return 2;
}