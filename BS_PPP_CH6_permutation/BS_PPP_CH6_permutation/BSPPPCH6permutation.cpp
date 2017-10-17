/*
The following programm as written in response to a prompt provided
by the book Progrmaming Principles and Practice by Bjarne Stroustrup.
This program was written in response to prompt 10 in chapter 6. The 
program computes the number of permutations or combinations of a and b.
As it is written, there are areas to improve: error checking is fairly
relaxed, and given the high likelihood of a factorial to grow, very 
fast, overflow of the data type is a real concern. Moreover, there is
an opportunity to optimize, and simplify the simplify*() function (the irony). 
However, as written, the program produces correct results for 
limited test cases. 
Author: Dan Vyenielo
Date: 10/16/17
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void prompt_user(unsigned int& a, unsigned int& b, char& computation_method);
unsigned int compute(const unsigned int& a, const unsigned int& b, 
	const char& computation_method);
unsigned int combination(const unsigned int& a, const unsigned int& b);
unsigned int permutation(const unsigned int& a, const unsigned int& b);
vector<unsigned int> expand_factorial(const unsigned int& n);
void simplify_fraction_of_products(vector<unsigned int>& numerator,
	vector<unsigned int>& denominator);
unsigned int product(vector<unsigned int>& terms);
void print(const unsigned int& result, const char& computation_method);

int main()
{
	try {
		unsigned int a = 0, b = 0, result = 0;
		char computation_method = 0;
		prompt_user(a, b, computation_method);
		result = compute(a, b, computation_method);
		print(result, computation_method);
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << '\n';
	}
	catch (...) {
		cerr << "Unknown error.\n";
	}
	return 0;
}

void prompt_user(unsigned int& a, unsigned int& b, char& computation_method) {
	cout << "-----------------------------------------------------------------------\n"
		 << "Welcome to the combination and permutation computation program.\n"
		 << "Combinations and permutations expect input in a choose b format;\n"
		 << "where a and b are integral numbers. Seperate input with whitespace.\n"
		 << "-----------------------------------------------------------------------\n";

	cout << "Would you like to compute a combination (c) or permutation (p)?\n";
	cin >> computation_method;
	if (computation_method == 'c') {
		cout << "Please enter two numbers to compute the number of possilbe combinations.\n";
		cin >> a >> b;
	}
	else if (computation_method == 'p') {
		cout << "Please enter two numbers to compute the number of possilbe permutations.\n";
		cin >> a >> b;
	}
	else
		throw exception("Invalid entry; options are 'p' or 'c'.");
	if (a - b < 0)
		throw exception("Invalid entry; a must be larger than b.");
}

unsigned int compute(const unsigned int& a, const unsigned int& b, const char& computation_method) {
	unsigned int result = 0;
	if (computation_method == 'c') {
		result = combination(a, b);
	}
	else if (computation_method == 'p') {
		result = permutation(a, b);
	}
	return result;
}

unsigned int combination(const unsigned int& a, const unsigned int& b) {
	vector<unsigned int> denominator = expand_factorial(b);
	return permutation(a, b) / product(denominator);	//integer division, not sure if always defined.
}

unsigned int permutation(const unsigned int& a, const unsigned int& b) {
	vector<unsigned int> numerator = expand_factorial(a);
	vector<unsigned int> denominator = expand_factorial(a - b);
	simplify_fraction_of_products(numerator, denominator);
	return product(numerator) / product(denominator);	//integer division, not sure if always defined.
}

vector<unsigned int> expand_factorial(const unsigned int& n) {
	vector<unsigned int> terms;
	for (unsigned int i = n; i > 0; i--)
		terms.push_back(i);
	return terms;
}

/*Simplify_fraction_of_products() could be optimized. All values
of the denominator up to the max term cancel with those same terms 
present in the numerator. Very inefficient as currently written.*/
void simplify_fraction_of_products(vector<unsigned int>& numerator, 
	vector<unsigned int>& denominator) {
	for (unsigned int i = 0; i < denominator.size(); i++)
	{
		for (unsigned j = 0; j < numerator.size(); j++) {
			if (denominator[i] == numerator[j])
			{
				denominator.erase(denominator.begin() + i);
				numerator.erase(numerator.begin() + j);
			}
		}
	}
}

unsigned int product(vector<unsigned int>& terms) {
	unsigned int product = terms[0];
	for (unsigned int i = 1; i < terms.size(); i++)
		product *= terms[i];	//may overflow
	return product;
}

void print(const unsigned int& result, const char& computation_method) {
	if (computation_method == 'c') {
		cout << "There are " << result << " possible combinations.\n";
	}
	else if (computation_method == 'p') {
		cout << "There are " << result << " possible permutations.\n";
	}
}