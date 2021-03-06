/*The following is my solution to prompt 944 Delete Columns To Make Sorted
from leetcode.com. The prompt and driver can be found here: 
https://leetcode.com/problems/delete-columns-to-make-sorted/
Author: Dan Vyenielo
*/
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		const unsigned size = A.size();
		const unsigned str_length = A[0].length();
		unsigned del_count = 0;
		for (unsigned col = 0; col < str_length; ++col) {
			for (unsigned row = 1; row < size; ++row) {
				if (A[row - 1][col] > A[row][col]) {
					++del_count;
					break;
				}
			}
		}
		return del_count;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}