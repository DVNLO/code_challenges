class Solution {
public:
    string 
    longestCommonPrefix(vector<string>& strs) 
    {
        char c;
        string prefix;
        if(strs.empty())
        {
            return prefix;
        }
        size_t const SIZE_STR0{ strs[0].size() };
        size_t const SIZE_STRS{ strs.size() };
        for(size_t i{ 0U }; i < SIZE_STR0; ++i)
        {
            c = strs[0][i];
            size_t j{ 1U };
            while(j < SIZE_STRS && strs[j][i] == c)
            {
                ++j;
            }
            if(j == SIZE_STRS)
            {
                prefix += c;
            }
            else // strs[j][i] != c
            {
                break;
            }
        }
        return prefix;
    }
};
