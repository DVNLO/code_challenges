// Can be done in O(1) space by simply tracking the last two entries
// but eh, I wanted to lay the ground work for DP. 
class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> ways_to_climb_stairs(n + 1);
        for(int i{ 0 }; i < 3 && i <= n; ++i)   // handle 0, 1, 2 base cases
            ways_to_climb_stairs[i] = i;
        for(int i{ 3 }; i <= n; ++i)
        {
            ways_to_climb_stairs[i] = ways_to_climb_stairs[i - 1] 
                                        + ways_to_climb_stairs[i - 2];
        }
        return ways_to_climb_stairs[n];
    }
};
