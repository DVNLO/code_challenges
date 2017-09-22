/*
* This program niavely converts unsigned decimal integer values to binary.
* There are more efficient programs, and algorithms which can be found
* here: https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting
* Author: Dan Vyenielo
* Date: 9/21/17
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
constexpr unsigned short BINARY_RADIX = 2;
void print_vector(const std::vector<int> &in);
unsigned int log_base2(const unsigned int &in);
unsigned int power(const unsigned int &base, const unsigned int &exp);
void unsigned_int_to_binary(const unsigned int &in, std::vector<int> &binary);

int main()
{
	unsigned int int_value = 1;
	while (int_value)	//count to ~4 trillion... Convert for each step. 
	{
		std::vector<int> binary;
		unsigned_int_to_binary(int_value, binary);
		std::cout << int_value << " ";
		print_vector(binary);
		int_value++;
	}
	return 0;
}

void print_vector(const std::vector<int> &in) {
	for (unsigned int i = 0; i < in.size(); i++)
		std::cout << in[i]; 
	std::cout << std::endl;
}

/*
* An input integer is converted to a vector of binary digits through  
* iteration by finding the most significant base two factor of the 
* the remainder. A vector is initialized to 0 values in the first
* iteration of the loop. Subsequent iterations insert 1's in the 
* position of the greatest base two factor until remainder is 0.
*/
void unsigned_int_to_binary(const unsigned int &in, std::vector<int> &binary) {
	unsigned int exp, quotient, remainder;
	remainder = in;
	while (remainder != 0)
	{
		exp = log_base2(remainder);	//position
		//std::cout << "exp::" << exp << std::endl;
		quotient = power(BINARY_RADIX, exp);
		//std::cout << "quotient::" << quotient << std::endl;
		remainder -= quotient;
		//std::cout << "remainder::" << remainder << std::endl;
		if (binary.size() <= exp) {
			binary.resize(exp + 1, 0);
		}	
		binary[binary.size() - exp - 1] = 1;	//coef of most significant power (listed most to least significant)
	}
}

unsigned int power(const unsigned int &base, const unsigned int &exp) {
	int product = 1;
	for (unsigned int i = 0; i < exp; i++)
		product *= base;
	return product;
}

unsigned int log_base2(const unsigned int &in) {
	unsigned int power = 0, product = 1;
	while (product <= in)
	{
		product *= BINARY_RADIX;
		//std::cout << "power::" << power << std::endl;
		power++;
	}
	return power - 1;
}