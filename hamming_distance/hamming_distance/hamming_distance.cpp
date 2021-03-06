/*
The following is a solution to prompt 461: Hamming Distance from leetcode.com.
Author: Dan Vyenielo
*/
#include "stdafx.h"
#include <iostream>

/*
Returns the Hamming distance between x and y. Where hamming distance is 
defined as the number of differing bits between two numbers. 
Example (from leetcode.com):
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
*/
int hammingDistance(int x, int y) {
	int hammed = x ^ y;
	int distance = 0;
	while (hammed != 0)
	{
		//division "algorithm" -> https://en.wikipedia.org/wiki/Division_algorithm
		distance += hammed % 2;
		hammed /= 2;
	}
	return distance;
}

int main()
{
	std::cout << hammingDistance(1, 4) << std::endl;
    return 0;
}