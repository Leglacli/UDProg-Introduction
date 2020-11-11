#include "std_lib_facilities.h"

// Token class
class Token {
public:
	char kind;
	double value;
	string name;

	// 3 constructors, kind is always needed
	Token(char ch) :kind{ ch } { }
	Token(char ch, double val) :kind{ ch }, value{ val } { }
	Token(char ch, string n) : kind{ ch }, name{ n } { }
};

class Token_stream {
public:
	Token_stream() :full{ false }, buffer{ 0 } { } // tokens from putback come here
	Token get(); // this is how we get the next token
	void putback(Token t) { buffer = t; full = true; } // puts back a token into the stream
	void ignore(char c); //ingores a char
private:
	bool full; // is the buffer full?
	Token buffer;
};

//Token kinds
const char let = '#';   // Directly the char to express variable declaration
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqrtch = 's';
const char powch = 'p';

// Keywords

const string quitkey = "exit";
const string sqrtkey = "sqrt";
const string powkey = "pow";

Token Token_stream::get()
{
	if (full) { full = false; return buffer; } //If the buffer has a token, clear it and return it

	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':   // separator for function arguments
	case let:   // for declaration
		return Token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ number, val };
	}
	default:
		if (isalpha(ch)) //if it's an undefined char
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == quitkey) return Token{ quit };
			if (s == sqrtkey) return Token{ sqrtch };
			if (s == powkey) return Token{ powch };
			return Token{ name,s };
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	// check if the buffer is full and it has c kind
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	// clear the buffer
	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

class Variable {
public:
	string name;
	double value;
};

vector<Variable> variables; //vector for variables

double get_value(string s)
{
	for (auto v : variables) //getting a variable's value from the vector
		if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (auto v : variables) //getting a variable from the vector and setting it to d's value
		if (v.name == s) {
			v.value = d;
			return;
		}

	error("set: undefined name ", s); //variable not found
}

bool is_declared(string s) //check if the variable is declared
{
	for (auto v : variables)
		if (v.name == s) return true;
	return false;
}

Token_stream ts;
double expression();

double pow_or_square(char c)
// Handles sqrt and pow
{
	vector<double> args;    // this is where function arguments are stored
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected after function name");

	// handle the arguments
	switch (c)
	{
	case sqrtch: //if its 's'
		args.push_back(expression()); //put it in the vector
		break;
	case powch: // if its 'p'
		args.push_back(expression());
		t = ts.get();
		if (t.kind != ',') error("Wrong number of arguments"); // pow() needs 2 arguments, if there are less or more, error
		args.push_back(expression());  //put it in the vector
		break;
	default: // no arguments, do nothing
		break;
	}

	t = ts.get(); //getting the next token
	if (t.kind != ')') error(" ')' expected after arguments"); // if there is no ')', error

	// sqrt and pow calculation
	switch (c)
	{
	case sqrtch:
		if (args[0] < 0) error("sqrt() cant be used for negative numbers");
		return sqrt(args[0]);
	case powch:
		return pow(args[0], args[1]);
	default: //if there is a name but not an implementation, error
		error("Function not implemented");
	}
}

double primary() // handles parantheses, positive and negative numbers, variables, sqrt() and pow()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return d;
	}
	case '-':   // negative number
		return -primary();
	case '+':   // positive number
		return primary();
	case number:
		return t.value;
	case name:  // get a variables value
		return get_value(t.name);
	case sqrtch:
	case powch:
		return pow_or_square(t.kind); //the function decides which one to do, if it's 's' it does sqrt(), if it's 'p' it does pow()
	default:
		error("primary expected");
	}
}

double term() //handles '*', '/' and '%'
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("division by zero");
		left /= d;
		break;
		}
		case '%':
		{   double d = primary();
		if (d == 0) error("division by zero");
		left = fmod(left, d);
		break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression() //handles '+', '-'
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration() // variable declaration
{
	Token t = ts.get();
	if (t.kind != name) error("variable name not found in declaration");
	string var_name = t.name;
	if (is_declared(var_name)) error(var_name, " already declared");

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	variables.push_back(Variable{ var_name,d });
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(); //if the token is 'let', let the user declare a variable
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true)
		try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		clean_up_mess();    // prompt user again
	}
}

int main()
try {
	cout << "---> Welcome, this is a simple calculator <---" << endl;
	cout << "---> You can use '+' , '-' , '*' , '/' , '%'(mod), sqrt(x) and pow(x,y), y must be int! <---" << endl;
	cout << "---> To print the result type ';' and to quit the program type 'exit' <---" << endl;

	// Predefined variable
	variables.push_back(Variable{ "k", 1000 });

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Uknown exception!\n";
	return 2;
}