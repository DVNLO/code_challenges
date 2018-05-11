// reverse_int.cpp : Defines the entry point for the console application.
//

//Recursively reverses integer input. Will overflow. Do not use in production code, until 
//resolving interger overflow.
//Author: Dan Vyenielo 10 May 2018

#include "stdafx.h"
#include <iostream>;

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
		return reverseInt(x / 10) + scaler * (x % 10);
	}
}

int main()
{
	std::cout << reverseInt(12345) << std::endl;
	std::cout << reverseInt(-12345) << std::endl;
	std::cout << reverseInt(1534236469) << std::endl;
    return 0;
}

