// The following is my second attempt at the problem. 
// I realized that if we have a sequence of 0, 1, 2, 3, ... , n
// we can compute the expected value of the sequence as a sum
// using the arithmetic series formula. And then we can subtrace
// all the values we find the nums from that expected sum, and
// we will be left with the missing value.
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        size_t const NUMS_SIZE{ nums.size() };
        long long expected_val{ ((NUMS_SIZE + 1) * NUMS_SIZE) >> 1 };
        for(size_t i{ 0 }; i < NUMS_SIZE; ++i)
        {
            expected_val -= nums[i];
        }
        return expected_val;
    }
};
