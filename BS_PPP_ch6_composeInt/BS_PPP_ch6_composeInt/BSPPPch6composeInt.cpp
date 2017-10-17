/*
The following program was composed in response to a prompt in the book
Programming Principles and Practice by Bjarne Stroustrup. The program
is a solution to exercise 9 in chapter 6, with slight modification.
This program parses character input and converts it into a linear
combination of terms using the base ten number system. Minor improvements
can be made, including: support for double number input and implementation
of a non-narrowing power function within compose_terms().
Author: Dan Vyenielo
Date: 10/16/17
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> compose_terms(const vector<char>& input);
void print(const vector<int>& input);
int sum_terms(const vector<int>& input);
void list_terms(const vector<int>& input);

int main()
{
	try {
		vector<char> input;
		char c;
		cin >> c;
		while (isdigit(c)) {
			input.push_back(c);
			cin >> c;
		}
		vector<int> terms = compose_terms(input);
		print(terms);
	}
	catch (exception& e) {
		cerr << "Error: " << e.what();
	}
    return 0;
}

vector<int> compose_terms(const vector<char>& input) {
	vector<int> terms;
	terms.resize(input.size());
	unsigned int j = input.size() - 1;
	for (unsigned int i = 0; i < input.size(); i++)
	{
		int k = input[i] - '0';	//convert char to int
		int term = k * pow(10, j);	//possible narrowing conversion
		terms[i] = term;	//most to least significant
		j--;
	}
	return terms;
}

void print(const vector<int>& input) {
	int value = sum_terms(input);
	cout << value << " is ";
	list_terms(input);
}

int sum_terms(const vector<int>& input) {
	int sum = 0;
	for (unsigned int i = 0; i < input.size(); i++)
		sum += input[i];
	return sum;
}

void list_terms(const vector<int>& input) {
	for (unsigned int i = 0; i < input.size(); i++) {
		if (i != (input.size() - 1))
			cout << input[i] << " and ";
		else
			cout << input[i];
	}
	cout << ".\n";
}