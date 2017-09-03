/*Inspiration for this program from Bjarne Stroustrup's Programming Principles 
and Practice pg. 105. This program explores the usage of if() statements in 
C++ via fictional currency conversion.
I had difficulty converting string data to all lower case for verifying user 
input validity. process_string_to_lower() utilizes code from stackexchange.
At this time ::tolower used within transform() is unclear syntax. 
Author: Dan Vyenielo
Date: 9/3/2017
*/

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void prompt_user(double &value, string &unit_in, string &unit_out);
bool is_value_valid(const double value);
bool is_unit_valid(const string unit);
void process_string_to_lower(string &in);
double currency_conversion(const double &value, const string &unit_in, 
	const string &unit_out);
void print_conversion_reciept(const double &value, const double &yield,
	const string &unit_in, const string &unit_out);


int main()
{
	double value = -1;
	string unit_in = "";
	string unit_out = "";
	double yield = -1;
	
	prompt_user(value, unit_in, unit_out);
	yield = currency_conversion(value, unit_in, unit_out);
	print_conversion_reciept(value, yield, unit_in, unit_out);
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

double currency_conversion(const double &value, const string &unit_in, 
	const string &unit_out) {
	//fictional conversion values
	constexpr double euro_to_usd = 123;
	constexpr double euro_to_yen = 50;
	constexpr double usd_to_euro = 75;
	constexpr double usd_to_yen = 321;
	constexpr double yen_to_euro = 100;
	constexpr double yen_to_usd = 123;

	double yield;
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

void print_conversion_reciept(const double &value,const double &yield,
	const string &unit_in,const string &unit_out) {
	cout << "Conversion successful." << endl;
	cout << value << ' ' << unit_in << " converted to " << yield << ' ' << unit_out << endl;
}