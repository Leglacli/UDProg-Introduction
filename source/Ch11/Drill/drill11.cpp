#include "std_lib_facilities.h"

int main()
try {
	int birth_year = 2000;
	int age = 20;

	cout << "Decimal\t\t" << birth_year << endl << hex << "Hexadecimal\t" << birth_year << endl << oct << "Octal\t\t" << birth_year << endl;
	cout << "\nAge " << dec << age << endl << endl;

	
	int a;
	int b;
	int c;
	int d;

	/*
	a gets normal decimal 1234
	b gets 1234 converted to octal = 668
	c and d gets 1234 converted to hexadecimal = 4660
	*/
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << endl;
	

	cout << 1234567.89 << " \t(defaultfloat)\n" << fixed << 1234567.89 << " \t(fixed)\n" << scientific << 1234567.89 << " \t(scientific)" << endl << endl;

	cout << '|' << setw(8) << "Czimerman" << '|' << setw(6) << "Alex" << '|' << setw(22) << "darklemon85@gmail.com" << '|' << setw(10) << "0779234233" << "|" << endl;
	cout << '|' << setw(9) << "First" << '|' << setw(5) << "Friend" << '|' << setw(22) << "firstfriend@gmail.com" << '|' << setw(10) << "0745812354" << "|" << endl;
	cout << '|' << setw(9) << "Second" << '|' << setw(5) << "Friend" << '|' << setw(22) << "secondfriend@gmail.com" << '|' << setw(10) << "0732242354" << "|" << endl;
	cout << '|' << setw(9) << "Third" << '|' << setw(5) << "Friend" << '|' << setw(22) << "thirdfriend@gmail.com" << '|' << setw(10) << "0745321254" << "|" << endl;
	cout << '|' << setw(9) << "Fourth" << '|' << setw(5) << "Friend" << '|' << setw(22) << "fourthfriend@gmail.com" << '|' << setw(10) << "0757232132" << "|" << endl;
	cout << '|' << setw(9) << "Fifth" << '|' << setw(5) << "Friend" << '|' << setw(22) << "fifthfriend@gmail.com" << '|' << setw(10) << "0795223452" << "|" << endl;

	return 0;

}
catch (exception& e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Something troubling occurred..\n";
	return 2;
}