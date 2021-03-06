// reverse_int.cpp : Defines the entry point for the console application.
//

//Recursively reverses integer input. Will overflow. Do not use in production code, until 
//resolving interger overflow. reverseOpt() is optimized for production!
//Author: Dan Vyenielo 30 May 2018

#include "stdafx.h"
#include <iostream>;

/*
int reverseInt(int x)
{
	if (x == 0)
	{
		return 0;
	}
	else if (x < 0)
	{
		return -1 * reverseInt(-1 * x);
	}
	else
	{
		int scaler = 1;
		while (scaler * 10 < x)
		{
			scaler *= 10;
		}
		int term = 0;
		try
		{
			 term = scaler * (x % 10);
		}
		catch(...)
		{
			return 0;
		}
		return reverseInt(x / 10) + term;
	}
}

int reverse(int x) {
	if (x == 0)
	{
		return 0;
	}
	bool isNegative = false;
	if (x < 0)
	{
		isNegative = true;
		x *= -1;
	}
	int count = 0;
	int scaler = 1;
	while (scaler * 10 < x)
	{
		scaler *= 10;
		count++;
	}
	int product = 0;
	int test_product = 0;
	int remainder = 0;
	int sum = 0;
	int test_sum = 0;
	for (int i = 0; i < count + 1; i++)
	{
		remainder = x % 10;
		test_product = scaler * remainder;  //possible overflow
		if (remainder != 0)
		{
			if (test_product / remainder != scaler)
			{
				return 0;   //overflow
			}
			else
			{
				product = test_product;   //no overflow
			}
		}
		test_sum = sum + product;   //possible overflow
		if (test_sum - product != sum)
		{
			return 0;   //overflow
		}
		else
		{
			sum += product;    //no overflow
		}
		x /= 10;
		scaler /= 10;
	}
	return isNegative ? -sum : sum;
}
*/

int reverseOpt(int x) {
	int result = 0;
	while (x)
	{
		int pr = (result * 10) + (x % 10);
		if (result != pr / 10) return 0;    //overflow
		result = pr;
		x /= 10;
	}
	return result;
}

int main()
{
	//std::cout << reverseInt(12345) << std::endl;
	//std::cout << reverseInt(-12345) << std::endl;
	//std::cout << reverseInt(1534236469) << std::endl;
	//std::cout << reverse(123) << std::endl;
	std::cout << reverseOpt(123) << std::endl;
    return 0;
}

