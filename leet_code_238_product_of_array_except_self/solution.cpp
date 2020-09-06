class Solution {
public:
    vector<int> 
    productExceptSelf(vector<int>& nums)
    {
        vector<int> ret;
        size_t SIZE_NUMS{ nums.size() };
        if(!SIZE_NUMS)
        {
            return ret;
        }
        else
        {
            ret.resize(SIZE_NUMS);
        }
        vector<int> forward_product(SIZE_NUMS);
        forward_product[0] = nums[0];
        for(size_t i{ 1U }; i < SIZE_NUMS; ++i)
        {
            forward_product[i] = forward_product[i - 1] * nums[i];
        }
        vector<int> backward_product(SIZE_NUMS);
        backward_product[SIZE_NUMS - 1] = nums[SIZE_NUMS - 1];
        for(size_t i{ SIZE_NUMS - 2U }; i < SIZE_NUMS; --i)
        {
            backward_product[i] = backward_product[i + 1] * nums[i];
        }
        ret[0] = backward_product[1];
        ret[SIZE_NUMS - 1] = forward_product[SIZE_NUMS - 2];
        for(size_t i{ 1U }; i < SIZE_NUMS - 1; ++i)
        {
            ret[i] = forward_product[i - 1] * backward_product[i + 1];
        }
        return ret;
    }
};
