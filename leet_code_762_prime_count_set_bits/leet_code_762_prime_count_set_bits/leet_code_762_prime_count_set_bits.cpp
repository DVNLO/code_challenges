/*
The following is a solution to prompt 762. Prime Number of Set Bits in Binary Representation
from leetcode.com. The prompt can be found here: 
https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <unordered_set>

class Solution {
public:
	/*
	bool isPrime(const int& x) {
	return (x == 2 || x == 3 || x == 5 || x == 7 ||
	x == 11 || x == 13 || x == 17 || x == 19);
	if(n == 1 || n == 0)
	return false;
	int sqrtN = round(sqrt(n));
	for(int i = 2; i <= sqrtN; i++) {
	if(!(n % i))
	return false;
	}
	return true;
	}
	*/

	int countPrimeSetBits(int L, int R) {
		int i = L;
		int primeCount = 0;
		std::unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };	//input constrained
		while (i <= R) {
			int n = i;
			int setCount = 0;
			while (n) {
				if (n % 2)
					setCount++;
				n /= 2;
			}
			if (primes.count(setCount))	//easier than find()
				primeCount++;
			i++;
		}
		return primeCount;
	}
};

int main()
{
	Solution prompt;
	prompt.countPrimeSetBits(2, 5);
    return 0;
}

