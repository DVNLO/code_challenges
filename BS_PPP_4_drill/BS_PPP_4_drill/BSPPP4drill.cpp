/*The following progarm is a drill excercise from Bjarne Stroustrup's
Programming Principles and Practice. The drill is taken from chapter 4. 
Author: Dan Vyenielo
Date: 9 September 2017*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void problems_1to5();
void problems_6to11();
bool is_unit_valid(const vector<string> &valid_units, const string &unit);
void convert_to_m(double &value, string &unit);
void echo_input(const double &value, const string &unit, double &min, double &max);
void print_vector(const vector<double> &input);

int main()
{
	//problems_1to5();
	problems_6to11();
    return 0;
}

/*
1) Write a program that reads two ints and prints them to screen.
Terminate the while loop via the | char.
2) Adapt the program to write out "the smaller value is:" x and
"the larger value is:" y.
3) Augment the program to write if the numbers are equal.
4) Use doubles instead of ints.
5) If the numbers are almost equal (+/- 1/100), print out
"the numbers are almost equal".
*/
void problems_1to5() {
	double one = 0, two = 0;
	char flag = 0, terminator = '|';

	//problem 1
	cout << "Enter two integer values. Terminate with | char." << endl;
	while (flag != terminator)
		cin >> one >> two >> flag;

	cout << "Problem 1  Output -----------------------------------------" << endl;
	cout << "int 1: " << one << " | int 2: " << two << endl;
	cout << endl;

	//problem 2
	double greater = 0, lesser = 0;
	if (one < two) {
		greater = two;
		lesser = one;
	}
	else if (two < one) {
		greater = one;
		lesser = two;
	}
	else {}	// do nothing.



	cout << "Problem 2 & 3 Output -----------------------------------------" << endl;
	/*
	if (greater == lesser) {
	cout << "The numbers are equal." << endl;
	}
	else {
	cout << "The smaller value is: " << lesser
	<< " | The larger value is: " << greater << endl;
	}
	*/
	cout << "The smaller value is: " << lesser
		<< " | The larger value is: " << greater << endl;

	//problem 5
	if (abs(one - two) < 0.01)
	{
		cout << "The numbers are almost equal." << endl;
	}

}

void problems_6to11() {
	const vector<string> valid_units = { "m", "cm", "in", "ft" };
	vector<double> input;
	double value = 0, min, max, sum = 0, count = 0;
	string unit = "";

	//get the first value for max and min to compare from.
	if (cin >> value >> unit && is_unit_valid(valid_units, unit))
	{
		convert_to_m(value, unit);
		min = value;
		max = value;
		echo_input(value, unit, min, max);
		input.push_back(value);
		sum += value;
		count++;
		while (cin >> value >> unit && is_unit_valid(valid_units, unit)) {
			convert_to_m(value, unit);
			echo_input(value, unit, min, max);
			input.push_back(value);
			sum += value;
			count++;
		}
	}
	sort(input.begin(), input.end());
	print_vector(input);
	cout << "The sum is " << sum << endl;
}

void echo_input(const double &value, const string &unit, double &min, double &max) {
	cout << endl << ">> " << value << unit;
	if (value < min) {
		min = value;
		cout << " the smallest so far." << endl;
	}
	if (max < value) {
		max = value;
		cout << " the largest so far." << endl;
	}
	cout << endl;
}

bool is_unit_valid(const vector<string> &valid_units, const string &unit) {
	bool validity = false;
	unsigned int i = 0;
	while (i < valid_units.size() && !validity)
	{
		if (valid_units[i] == unit)
			validity = true;
		i++;
	}
	return validity;
}

void convert_to_m(double &value, string &unit) {
	constexpr double cm_to_m = 0.01;
	constexpr double in_to_cm = 2.54;
	constexpr double ft_to_in = 12;

	if (unit == "ft") {
		value *= ft_to_in;
		unit = "in";
	}
	if (unit == "in")
	{
		value *= in_to_cm;
		unit = "cm";
	}
	if (unit == "cm")
	{
		value *= cm_to_m;
		unit = "m";
	}
}
void print_vector(const vector<double> &input) {
	for (unsigned int i = 0; i < input.size(); i++)
	{
		cout << input[i] << ' ';
	}
	cout << endl;
}


