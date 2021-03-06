/*
The following is a solution to prompt 349. Intersection of Two Arrays from 
leetcode.com. Original prompt here: 
https://leetcode.com/problems/intersection-of-two-arrays/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<int> res;
		if (nums1.size() >= nums2.size()) {   //use larger as lookup
			std::unordered_set<int> lookup(nums1.begin(), nums1.end());
			for (int num : nums2) {   //iterate through the smaller
				if (lookup.count(num)) {
					res.push_back(num);
					lookup.erase(num);    //remove num from the lookup so we don't double add to result.
				}
			}
		}
		else {  //2 is larger than 1, try again with the params swapped.
			return intersection(nums2, nums1);
		}
		return res;
	}

	/*
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> res;
		if(!nums1.size() || !nums2.size())
			return vector<int>(0);
		if(nums1.size() >= nums2.size()){
			unordered_set<int> lookup(nums1.begin(), nums1.end());
			for(int num : nums2){
				if(lookup.count(num) && !res.count(num)){
					res.insert(num);
				}
			}
		}
		else{
			return intersection(nums2, nums1);
		}
		return vector<int>(res.begin(), res.end());
	}
	*/
};

int main()
{
    std::cout << "Hello World!\n"; 
}