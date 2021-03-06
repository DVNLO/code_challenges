/*
The following is a solution to prompt 371. Sum of Two Integers
from leetcode.com. Included are some of the incorrect iterations
I went through while thinking about the problem. Both incorrect
solutions forget to consider the possibility of collisions between
the XOR and AND operations, effectively forgetting the carry
bit when this occurs, thus positive additions were consistently low. 
The correct solution continually performs XOR between A and B. The 
operations continues as long as the carry, which is stored in B, 
has a non-zero value.
The prompt can be found here: https://leetcode.com/problems/sum-of-two-integers/description/
A helpful discussion regarding bitwise operations was posted here: https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>

class Solution {
public:
	int getSum(int a, int b) {
		/*	//1
			int c = a ^ b;  //XOR
			int d = a & b;  //AND
			d <<= 1;    //LS(1)
			int e = c | d;  //OR
			return e;
		*/
		/*	//2
			return (a ^ b) | (a & b) << 1;  //simplified, incorrect
		*/
		/*
		//3
		while(b){
			int c = a;
			a ^= b;
			b = (c & b) << 1;
		}
		return a;
		*/
		//4
		int sum = a;
		while (b) {
			sum ^= b;
			b = (a & b) << 1;
			a = sum;
		}
		return sum;
	}
};

int main()
{
	Solution prompt;
	std::cout << prompt.getSum(20, 30) << '\n';
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
