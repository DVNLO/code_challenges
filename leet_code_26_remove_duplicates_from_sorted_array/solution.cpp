#include <cstdio>
#include <vector>

class Solution {
public:
    
    // Surprisingly, this algorithm took the same time as the others
    // according to leetcode. This is enough at this point.
    int removeDuplicates_2(std::vector<int>& nums)
    {
        std::size_t const SIZE{ nums.size() };
        if(!SIZE)
        {
            return 0;
        }
        std::size_t i{ static_cast<std::size_t>(0) };
        for(std::size_t j = 1; j < SIZE; ++j)
        {
            if(nums[i] != nums[j])
            {   
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
	
    // Interestingly, these two functions, 0 and 1, using iterators and
    // raw pointers explictly execute in roughly the same execution time.
    // Therefore, it would likely be more performant, to attempt a slightly
    // different algorithm....
    int removeDuplicates_1(std::vector<int>& nums)
    {
	if(nums.empty())
	{
	    return 0;
	}
	auto SIZE{ nums.size() };
        int * left{ &nums[0] };
	int * right{ &nums[0] };
	int const * const END{ &nums[SIZE] };
        do
	{
	    *left = *right;
	    while(right != END
	          && *left == * right)
	    {
		++right;
	    }
	    ++left;
	} while(right != END);
	return left - &nums[0];
    }
    
    int removeDuplicates_0(std::vector<int>& nums)
    {
        if(nums.empty())
        {
            return 0;
        }
	std::vector<int>::iterator left{ nums.begin() };
	std::vector<int>::iterator right{ left };
	std::vector<int>::const_iterator const END{ nums.cend() };
        do
        {
            *left = *right;
            while(right != END 
                  && *left == *right)
            {
                ++right;
            }
            ++left;
        } while (right != END);
        return left - nums.cbegin();
    }
};

int main()
{
    Solution s;
    std::vector<int> vi{ 1, 1, 1, 1, 2, 2, 2, 3, 3, 3 };
    int const LENGTH = s.removeDuplicates_2(vi);
    std::printf("LENGTH == %d\n", LENGTH);
    for(auto val : vi)
    {
	std::printf("%d\n", val);
    }
}
