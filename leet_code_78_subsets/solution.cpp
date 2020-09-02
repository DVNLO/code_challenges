class Solution {
public:
    vector<vector<int>> 
    subsets(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        ret.push_back({});
        size_t const SIZE_NUMS{ nums.size() };
        for(size_t i{ 0U }; i < SIZE_NUMS; ++i)
        {
            size_t const SIZE_RET{ ret.size() };
            for(size_t j{ 0U }; j < SIZE_RET; ++j)
            {
                vector<int> next(ret[j]);
                next.push_back(nums[i]);
                ret.push_back(next);
            }
        }
        return ret;
    }
};
