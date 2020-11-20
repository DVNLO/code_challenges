// This really was back to basics. But it lead to an interesting
// exploration of iterator and index based iteration. The array 
// based indexing proved to be faster. Moreover, using auto 
// with the begin and end functions would allow the iterators 
// to be container independent. 
//
class Solution {
public:
    int removeElement_size_t(vector<int>& nums, int val) 
    {
        int new_length{ static_cast<int>(nums.size()) };
        size_t l{ 0U };
        size_t r{ 0U };
        size_t const SIZE_NUMS{ nums.size() };
        while(r < SIZE_NUMS)
        {
            if(nums[r] != val)
            {
                nums[l] = nums[r];
                ++l;
                ++r;
            }
            else
            {
                --new_length;
                ++r;
            }
        }
        return new_length;
    }
    
    int removeElement(vector<int>& nums, int val) 
    {
        int new_length{ static_cast<int>(nums.size()) };
        auto l{ begin(nums) };
        auto r{ begin(nums) };
        auto const NUMS_END{ end(nums) };
        while(r < NUMS_END)
        {
            if(*r != val)
            {
                *l = *r;
                ++l;
                ++r;
            }
            else
            {
                --new_length;
                ++r;
            }
        }
        return new_length;
    }
};
