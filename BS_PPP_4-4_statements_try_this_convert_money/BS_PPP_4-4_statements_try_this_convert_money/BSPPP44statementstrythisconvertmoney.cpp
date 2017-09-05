/*Inspiration for this program from Bjarne Stroustrup's Programming Principles 
and Practice pg. 105. This program explores the usage of if() and case 
statements in C++ via fictional currency conversion. I explored a different if - else
structure which more accuratly represents the processing of if statements in 
string_to_currencyChar(). The code structure is more difficult to read, but easier
to understand how the if statements are executed, and shows the lack of else-if statements
in C++. The code structure emphasizes the nesting of the if statements. 
I had difficulty converting string data to all lower case for verifying user 
input validity. process_string_to_lower() utilizes code from stackexchange.
At this time ::tolower used within transform() is unclear syntax. 
Author: Dan Vyenielo
Date: 9/4/2017
*/

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//fictional conversion values
constexpr double euro_to_usd = 123;
constexpr double euro_to_yen = 50;
constexpr double usd_to_euro = 75;
constexpr double usd_to_yen = 321;
constexpr double yen_to_euro = 100;
constexpr double yen_to_usd = 123;

void prompt_user(double &value, string &unit_in, string &unit_out);
bool is_value_valid(const double value);
bool is_unit_valid(const string unit);
void process_string_to_lower(string &in);
double currency_conversion_nestedIf(const double &value, const string &unit_in, 
	const string &unit_out);
double currency_conversion_caseState(const double &value, const string &unit_in,
	const string &unit_out);
char string_to_currencyChar(const string &unit_in);
void print_conversion_reciept(const double &value, const double &yield,
	const string &unit_in, const string &unit_out);


int main()
{
	double value = -1;
	string unit_in = "";
	string unit_out = "";
	double yield_nestedIf = -1;
	double yield_caseStatement = -1;

	prompt_user(value, unit_in, unit_out);
	yield_nestedIf = currency_conversion_nestedIf(value, unit_in, unit_out);
	yield_caseStatement = currency_conversion_caseState(value, unit_in, unit_out);
	cout << "Printing conversion reciept for nested if structure." << endl;
	print_conversion_reciept(value, yield_nestedIf, unit_in, unit_out);
	cout << "Printing conversion reciept for case statement structure." << endl;
	print_conversion_reciept(value, yield_caseStatement, unit_in, unit_out);
    return 0;
}

void prompt_user(double &value, string &unit_in, string &unit_out) {
	while (!(is_value_valid(value)) || !(is_unit_valid(unit_in)))
	{
		cout << "Enter a value and unit (euro, usd, and yen) seperated by a space: ";
		cin >> value >> unit_in;
		process_string_to_lower(unit_in);
		if (!(is_value_valid(value)))
		{
			cout << "Please enter a positive, non-zero, value." << endl;
		}
		if (!(is_unit_valid(unit_in)))
		{
			cout << "Please enter a valid unit." << endl;
		}
	}
	while (!(is_unit_valid(unit_out)))
	{
		cout << "Enter a unit to convert to: ";
		cin >> unit_out;
		process_string_to_lower(unit_out);
		if (!(is_unit_valid(unit_out)))
		{
			cout << "Please enter a valid unit." << endl;
		}
	}
}

bool is_value_valid(const double value) {
	return(value > 0);
}

bool is_unit_valid(const string unit) {
	return ((unit == "euro") || (unit == "usd") || (unit == "yen"));
}


void process_string_to_lower(string &data) {
	//poached from:https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case/24063783#24063783
	transform(data.begin(), data.end(), data.begin(), ::tolower);
}

double currency_conversion_nestedIf(const double &value, const string &unit_in,
	const string &unit_out) {

	double yield = 0;
	if (unit_in == "euro")
	{
		if (unit_out == "usd")
			yield = value * euro_to_usd;
		if (unit_out == "yen")
			yield = value * euro_to_yen;
	}
	else if (unit_in == "usd")
	{
		if (unit_out == "euro")
			yield = value * usd_to_euro;
		if (unit_out == "yen")
			yield = value * usd_to_yen;
	}
	else if (unit_in == "yen")
	{
		if (unit_out == "euro")
			yield = value * yen_to_euro;
		if (unit_out == "usd")
			yield = value * yen_to_usd;
	}
	else
		cout << "Error during currency conversion." << endl;
	return yield;
}

double currency_conversion_caseState(const double &value, const string &unit_in,
	const string &unit_out) {

	double yield = 0;
	char temp_in = string_to_currencyChar(unit_in);
	char temp_out = string_to_currencyChar(unit_out);
	switch (temp_in)
	{
	case 'e':
		switch (temp_out)
		{
		case 'u':
			yield = value * euro_to_usd;
			break;
		case 'y':
			yield = value * euro_to_yen;
			break;
		}
		break;
	case 'u':
		switch (temp_out)
		{
		case 'e':
			yield = value * usd_to_euro;
			break;
		case 'y':
			yield = value * usd_to_yen;
			break;
		}
		break;
	case 'y':
		switch (temp_out)
		{
		case 'e':
			yield = value * yen_to_euro;
			break;
		case 'u':
			yield = value * yen_to_usd;
			break;
		}
		break;
	default:
		cout << "Error during currency conversion." << endl;
		break;
	}
	return yield;
}

char string_to_currencyChar(const string &unit_in) {
	char unit = 0;
	if (unit_in == "euro")
	{
		unit = 'e';
	}
	else
	{
		if (unit_in == "usd")
		{
			unit = 'u';
		}
		else
		{
			if (unit_in == "yen")
			{
				unit = 'y';
			}
			else
			{
				cout << "Error during string to char conversion." << endl;
			}
		}
	}
	return unit;
}

void print_conversion_reciept(const double &value,const double &yield,
	const string &unit_in,const string &unit_out) {
	cout << "Conversion successful." << endl;
	cout << value << ' ' << unit_in << " converted to " << yield << ' ' << unit_out  << '.' << endl;
}