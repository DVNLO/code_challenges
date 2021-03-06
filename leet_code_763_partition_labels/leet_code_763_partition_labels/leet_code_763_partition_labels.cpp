/*
The following is a solution to prompt 763 Partition Labels from leetcode.com.
Credit for this code should be attributed to the @awice. My solution is not 
included, as it was O(N^2) complexity. The presented solution is O(N)
complexity. I provide a commentary for my future reference, as well as a
discussion reagarding what I was thinking at the time.
The prompt can be found here: https://leetcode.com/problems/partition-labels/solution/
*/

#include "pch.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	/*
	This algorithm partitions a string S of characters into as many unique sets
	of characters as possible. The algorithm scans S to determine the maximum 
	position of every character in S. Next, S is iterated over again, this time
	searching for the maximum "width" of a substring in S. This is accomplished
	by finding the maximum index x of characters in the interval from i to j.
	When i is equal to j, we have found the longest substring for the current
	"anchor" position. We store this count, move the anchor to the right of
	our iteration i, and then continue searching the remainder of the string, 
	forming subsets until the end. Note: the code does utilize one ASCII 
	to unsigned conversion trick S[i] - 'a' will produce an index position for
	the i-th character of S where we base the position on the ASCII offset from
	'a'.
	*/
	vector<int> partitionLabels(string S) {
		const unsigned size = S.size();
		unsigned max_idx[26];   //26 lowercase char
		for (unsigned i = 0; i < size; ++i)
			max_idx[S[i] - 'a'] = i;
		unsigned j = 0;
		unsigned anchor = 0;
		vector<int> ans;
		for (unsigned i = 0; i < size; ++i)
		{
			j = max(j, max_idx[S[i] - 'a']);
			if (i == j)
			{
				ans.push_back(i - anchor + 1);
				anchor = i + 1;
			}
		}
		return ans;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}