class Solution {
public:
    vector<int> 
    smallerNumbersThanCurrent(vector<int>& nums) 
    {
        size_t constexpr MAX_VAL{ 100U };
        unsigned val_count_map[MAX_VAL + 1]{ 0U };
        for(size_t i{ 0U }; i < nums.size(); ++i)
        {
            ++val_count_map[nums[i]];
        }
        unsigned less_than_count{ 0U };
        unsigned less_than_count_map[MAX_VAL + 1];
        for(size_t i{ 0U }; i <= MAX_VAL; ++i)
        {
            if(val_count_map[i])
            {
                less_than_count_map[i] = less_than_count;
                less_than_count += val_count_map[i];
            }
        }
        vector<int> ret(nums.size());
        for(size_t i{ 0U }; i < nums.size(); ++i)
        {
            ret[i] = less_than_count_map[nums[i]];
        }
        return ret;
    }
};
