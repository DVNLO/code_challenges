#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int>::size_type const SIZE{ digits.size() };
        vector<int> ret(SIZE);
        int carry{ 1 };
        for(int i{ SIZE - 1 };
            i >= 0;
            --i)
        {
            if(carry)
            {
                ret[i] = digits[i] + carry;
                if(ret[i] > 9)
                {
                    ret[i] = 0;
                    carry = 1;
                }
                else
                    carry = 0;
            }
            else
                ret[i] = digits[i];
        }
        if(carry)
        {
            ret[0] = 1;
            ret.push_back(0);
        }
        return ret;
    }
};
