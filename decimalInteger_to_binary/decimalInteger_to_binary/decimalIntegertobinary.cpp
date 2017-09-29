// decimalIntegertobinary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

constexpr int BINARY_RADIX = 2;
void convertToBinary(unsigned int n);

int main()
{
	int in;
	cin >> in;
	convertToBinary(in);
    return 0;
}

int log_2(const int& value) {
	int power = 0, product = 1;
	while (product != value)
	{
		product *= BINARY_RADIX;
		power++;
	}
	return power;
}

/**
* Takes a positive integer, converts it into binary and prints it to the console.
* @param n the number to convert and print
*/
void convertToBinary(unsigned int n)
{
	if (n / 2 != 0) {
		convertToBinary(n / 2);
	}
	printf("%d", n % 2);
}
