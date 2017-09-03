// BSPPP44statementstrythisconvertmoney.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool is_value_valid(const double value);
bool is_unit_valid(const string unit);
void process_string_to_lower(string &in);

int main()
{
	double value = -1;
	string unit_in = "";
	string unit_out = "";
	
	prompt_user(value, unit_in);
	currency_conversion(value, unit_in, unit_out);
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

void currency_conversion(double &value, string &unit_in, string &unit_out) {
	constexpr double yen_to_usd = 123;
	constexpr double usd_to_yen = 321;
	constexpr double yen_to_euro = 100;
	constexpr double euro_to_yen = 50;
	constexpr double euro_to_usd = 123;
	constexpr double usd_to_euro = 75;

	if (unit_in == "euro")
	{
		if (unit_out == "usd")
		{

		}
		if (unit_out == "yen")
		{

		}
	}
	if (unit_in == "usd")
	{
		if (unit_out == "euro")
		{

		}
		if (unit_out == "yen")
		{

		}
	}
	if (unit_in == "yen")
	{
		if (unit_out == "euro")
		{

		}
		if (unit_out == "usd")
		{

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
	transform(data.begin(), data.end(), data.begin(), ::tolower);
}
