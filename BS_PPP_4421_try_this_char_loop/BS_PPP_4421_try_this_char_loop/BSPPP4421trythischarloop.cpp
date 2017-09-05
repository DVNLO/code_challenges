/*
This program iterates on the range a-z while printing
the corresponding ASCII value for the current value 
of the control variable. type{value} narrowing preventing
syntax is utilized for conversion between int and char data
types. Implicit conversion of control is utilized by the 
post-increment statement at the end of the while loop.
Original inspiration for this program for Bjarne Stroustrup's
book Programming Principles and Practice (PPP) pg. 111.
Author: Dan Vyenielo
Date: 9/4/2017
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char control = 'a';
	while (int{ control } <= int{ 'z' })
	{
		cout << control << ' ' << int{ control } << endl;
		control++;
	}
    return 0;
}

