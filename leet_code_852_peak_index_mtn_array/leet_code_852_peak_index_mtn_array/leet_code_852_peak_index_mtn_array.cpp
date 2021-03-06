/*
The following functions are solutions to the prompt
852. Peak Index in a Mountain Array from leetcode.com.
"...LS()" utilizes linear searcg. "...BS()" utilizes
binary search. The prompt can be found here:
https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

class Solution {
public:
	//linear search
	int peakIndexInMountainArrayLS(std::vector<int>& A) {  //A is assumed to be a mountain.
		int i = 0;
		int finalComparisonIndex = A.size() - 2;
		while (i < finalComparisonIndex && A[i] < A[i + 1])
			i++;
		return i;
	}

	//binary search - modified example code from leetcode.com for learning
	int peakIndexInMountainArrayBS(std::vector<int>& A) {  //A is assumed to be a mountain.
		int lower = 0;
		int upper = A.size() - 1;
		while (lower < upper)  //A.size >= 3
		{
			int mid = lower + (upper - lower) / 2;
			if (A[mid] < A[mid + 1])
				lower = mid + 1;
			else
				upper = mid;
		}
		return lower;
	}
};

int main()
{
	Solution prompt;
	std::vector<int> A{12, 42, 53, 70, 25, 22, 20, 19};
	std::cout << prompt.peakIndexInMountainArrayLS(A) << std::endl;
	std::cout << prompt.peakIndexInMountainArrayBS(A) << std::endl;
    return 0;
}

