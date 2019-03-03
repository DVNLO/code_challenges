/* The following is a solution to leetcode prompt 674 Longest Continuous
 * increasing subsequence. The original prompt can be found here:
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 * Author: Dan Vyenielo
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const unsigned size = nums.size();
        if(!size)
            return 0;
        unsigned i = 1;
        int max_contin_count = 1;
        while(i < size)
        {
            int count = 1;
            while(i < size && nums[i - 1] < nums[i])
            {
                ++count;
                ++i;
            }
            max_contin_count = max(max_contin_count, count);
            ++i;
        }
        return max_contin_count;
    }
};

