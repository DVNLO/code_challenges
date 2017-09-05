/*This program computes a square utilizing a while loop. 
Original inspiration for the problem provided by Bjarne Stroustrup's
book Programming Principles and Practice pg. 116.
Author: Dan Vyenielo
Date: 9/4/2017
*/

#include "stdafx.h"
#include <iostream>

int square_by_addition(const int &value) {
	int result = 0;
	while (result != (value * value)) { //potential for strange behavior
		result += value;	
	}
	return result;
}

int main()
{
	int value = 0;
	int square = square_by_addition(value);
	std::cout << square << std::endl;
	return 0;
}

