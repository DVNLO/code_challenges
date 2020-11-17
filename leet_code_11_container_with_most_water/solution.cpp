// brute force and pointer method solutions.

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int max_area{ 0 };
        if(height.empty())
        {
            return max_area;
        }
        vector<int>::const_iterator lhs{ height.begin() };
        vector<int>::const_iterator rhs{ height.end() - 1 };
        while(lhs < rhs)
        {
            int const lhs_height{ *lhs };
            int const rhs_height{ *rhs };
            int const water_height = min(lhs_height, rhs_height);
            int const area = distance(lhs, rhs) * water_height;
            max_area = max(max_area, area);
            // move the iterator with min height closer to the other
            if(lhs_height < rhs_height)
            {
                ++lhs;
            }
            else
            {
                --rhs;
            }
        }
        return max_area;   
    }

    int max_area_brute_force(vector<int>& height) 
    {
        int max_area{ 0 };
        size_t const SIZE_HEIGHT{ height.size() };
        for(size_t i{ 0 }; i < (SIZE_HEIGHT - 1); ++i)
        {
            int const left_height = height[i];
            for(size_t j{ i + 1 }; j < SIZE_HEIGHT; ++j)
            {
                int const right_height = height[j];
                int const water_height = min(left_height, right_height);
                int const area = (j - i) * water_height;
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};
