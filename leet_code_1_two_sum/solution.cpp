// This is an excellent problem. I really struggled
// with it for a while, expecially because there are many
// edge cases to consider. For example, what if the array
// contains duplicates, it is of size 1, etc. After several
// failed attempts at designing an algorithm which worked
// in the general case, I realized that if the current
// value we are iterating on has already been seen in 
// the difference set iteration can stop because we've
// found the value pair. However, the prompt is asking
// for the indexes, so we store key value pairs in an 
// unordered map mapping the difference to the index it
// was computed for. So, we then just return a pair of 
// the current index and the index the difference was 
// computed for. 
// The prompt for the problem can be found here:
// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> diff_to_idx;
        vector<int> ret(2);
        int const SIZE = nums.size();
        for(int i{ 0 };
            i < SIZE;
            ++i)
        {
            if(diff_to_idx.count(nums[i]))
            {
                ret[0] = diff_to_idx[nums[i]];
                ret[1] = i;
                return ret;
            }
            diff_to_idx[target - nums[i]] = i;
        }
        return vector<int>();
    }
};
