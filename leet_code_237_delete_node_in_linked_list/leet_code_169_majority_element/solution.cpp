class Solution {
public:
    /* Returns the majority element found in nums. A
     * majority element has the property that its frequency
     * is greater than half the number of elements in the 
     * input vector, nums. Mathematically,  
     * freq(majority_element) > floor(size(nums) / 2);
     */
    int majorityElement(vector<int>& nums) 
    {
        size_t const nums_size{ nums.size() };
        if(nums_size <= static_cast<size_t>(1U))
            return nums[0];
        int const lower_bound_majority_element{ nums_size / 2U }; 
        unordered_map<int, unsigned> num_counts;
        for(auto const num : nums)
        {
            if(num_counts.count(num))
                ++num_counts[num];
            else
                num_counts[num] = 1U;
            if(num_counts[num] > lower_bound_majority_element)
                return num;
        }
        return 0;
    }
};
