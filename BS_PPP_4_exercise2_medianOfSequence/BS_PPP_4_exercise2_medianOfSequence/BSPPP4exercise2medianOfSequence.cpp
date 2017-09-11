/*This program computes the median value of a
sequence of integers. median()'s parameter is 
passed by value to copy the contents to a temporary
sequence for the life of the function.
Original prompt from Bjarne Stroustrup's Programming
Principles and Practice chapter 4 exercise 2. 
Author: Dan Vyenielo
Date: 9/10/17*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> sequence;
	median(sequence);
    return 0;
}

int median(vector<int> sequence) {
	int median, midpoint = (sequence.size() / 2);
	sort(sequence.begin(), sequence.end());
	if (sequence.size() % 2 == 0)	//even number of elements in sequence
	{
		median = (sequence[midpoint - 1] + sequence[midpoint + 1])
					/ 2;
	}
	else
		median = sequence[midpoint];
	return median;
}
