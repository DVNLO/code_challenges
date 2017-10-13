/*Programmed by Dan Vyenielo on October 12, 2017.*/
#include "stdafx.h"
#include "std_lib_facilities.h"

/*
2. The following program takes in a temperature value in Celsius and converts
it to Kelvin. This code has many errors in it. Find the errors, list
them, and correct the code.
double ctok(double c) // converts Celsius to Kelvin
{
int k = c + 273.15;
return int
}
int main()
{
double c = 0; // declare input variable
cin >> d; // retrieve temperature to input variable
double k = ctok("c"); // convert temperature
Cout << k << '/n' ; // print out temperature
}

3. Absolute zero is the lowest temperature that can be reached; it is –273.15°C,
or 0K. The above program, even when corrected, will produce erroneous
results when given a temperature below this. Place a check in the
main program that will produce an error if a temperature is given below
–273.15°C.

4. Do exercise 3 again, but this time handle the error inside ctok().
*/

double ctok(double c) // converts Celsius to Kelvin
{
	if (c < -273.15) {
		throw runtime_error("Enter Celcius value greater than or equal to -273.15.");
	}
	double k = c + 273.15;
	return k;
}


void problem2to4() {
	double c = 0; // declare input variable
	cin >> c; // retrieve temperature to input variable
	
	/*//Problem3 Method
	while(c < -273.15) {
		cout << "Enter a number greater than -273.15 C.";
		cin >> c;
	}
	*/
	double k = 0;
	try {
		k = ctok(c); // convert temperature
		cout << k << '\n'; // print out temperature
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << "\n";
	}
}


void quadratic_prompt(double& a, double& b, double& c) {
	cout << "Please enter values for a, b, and c. Seperate values with whitespace.\n";
	cin >> a >> b >> c;
}

double compute_quadratic_root(const double& a, const double& b, const double& c, const string& root) {
	double x = 0;
	double radican_value = (b*b) - (4 * a*c);
	if (radican_value < 0)
		throw runtime_error("Non-real result.");
	else if (root == "positive")
		x = (-b + sqrt(radican_value)) / (2 * a);
	else if (root == "negative")
		x = (-b - sqrt(radican_value)) / (2 * a);
	return x;
}

void problem7() {
	double a = 0, b = 0, c = 0, x_positive = 0, x_negative = 0;
	quadratic_prompt(a, b, c);
	//Quadratic equation may have two roots
	try {
		x_positive = compute_quadratic_root(a, b, c, "positive");
		x_negative = compute_quadratic_root(a, b, c, "negative");
		cout << "Quadriatic roots:: Postive: x = " << x_positive << " Negative: x = " << x_negative << '\n';
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << '\n';
	}
}

void prompt(unsigned int& n, vector<double>& list, string& numbers) {
	cout << "Please enter the numbers of integers you would like to sum:";
	cin >> n;
	cout << "Please enter some integers (press | to stop):\n";
	string entry = "\n";
	cin >> entry;
	while (entry != "|") {
		list.push_back(stod(entry));	//stod() throws invalid argument exception
		if (list.size() <= n) {
			numbers += (entry + ' ');
		}
		cin >> entry;
	}
}

void parse(const unsigned int& n, const vector<double>& list, double& sum) {
	for (unsigned int i = 0; i < n; i++) {
		sum += list[i];
	}
}

void print(const unsigned int& n, const string& numbers, const double& sum) {
	cout << "The sum of the first " << n << " numbers ( " << numbers << " ) is " << sum << ".\n";
}

void problem8to10() {
	unsigned int n = 0;
	double sum = 0;
	vector<double> list;
	string numbers;
	try {
		prompt(n, list, numbers);
		parse(n, list,sum);
		print(n, numbers, sum);
	}
	catch (invalid_argument& e) {
		cerr << "Error: " << e.what() << ".\n";
	}
	catch (out_of_range& e) {
		cerr << "Error: " << e.what() << '\n';
	}
}

/*11. Write a program that writes out the first so many values of the Fibonacci
series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
number of the series is the sum of the two previous ones. Find the largest
Fibonacci number that fits in an int.*/
void problem11() {
	try
	{
		//copied Bjarne's solution from: http://www.stroustrup.com/Programming/Solutions/Ch5/e5-10.cpp.
		int n = 1, m = 2;
		while (n<m) {
			cout << n << '\n';
			int x = n + m;
			n = m;	// drop the lowest number
			m = x;	// add a new highest number
		}
		cout << "the largest Fibonacci number that fits in an int is " << n << '\n';
	}
	catch (runtime_error e) {	// this code is to produce error messages
		cout << e.what() << '\n';
	}
}

int main()
{
	cout << "--------------------------------------------------------------\n";
	cout << "Bjarne Stroustrup: Programming Principles and Practice\n";
	cout << "Chapter 5 Errors: Exerciese\n";
	
	cout << "--------------------------------------------------------------\n";
	cout << "Problem::2-4\n";
	problem2to4();
	
	cout << "--------------------------------------------------------------\n";
	cout << "Skipping Problems 5-6\n";
	
	cout << "--------------------------------------------------------------\n";
	cout << "Problem::7\n";
	problem7();
	
	cout << "--------------------------------------------------------------\n";
	cout << "Problem::8-10\n";
	cout << "Skipped the difference vector in problem 10.\n";
	problem8to10();

	cout << "--------------------------------------------------------------\n";
	cout << "Problem::11\n";
	problem11();

	return 0;
}

