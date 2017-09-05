/*
This program iterates on the range a-z and A-Z while printing
the corresponding ASCII value for the current value 
of the control variable. type{value} narrowing preventing
syntax is utilized for conversion between int and char data
types. Implicit conversion of control is utilized by the 
post-increment statement at the end of the loops.
Original inspiration for this program for Bjarne Stroustrup's
book Programming Principles and Practice (PPP) pg. 111 and 113.
Author: Dan Vyenielo
Date: 9/4/2017
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	
	cout << "Print the ASCII char and value from a-z and A-Z, respectively, using a while loop." << endl;
	char while_control = 'a';
	while (int{ while_control } <= int{ 'z' })
	{
		//print lowercase then uppercase
		cout << while_control << ' ' << int{ while_control } << ' '
			<< char( toupper(while_control) ) << ' ' << int{ toupper(while_control) } << endl;	//in-range conversion to char.
		while_control++;
	}
	cout << "Print the ASCII char and value from a-z and A-Z, respectively, using a for loop." << endl;
	for (char for_control = 'a'; for_control <= 'z'; for_control++)
	{
		//print lowercase then uppercase
		cout << for_control << ' ' << int{ for_control } << ' '
			<< char( toupper(for_control) ) << ' ' << int{ toupper(for_control) } << endl;	//in-range conversion to char.
	}
    return 0;
}

