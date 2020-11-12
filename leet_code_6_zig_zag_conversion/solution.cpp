class Solution {
public:
    string convert(string s, int row_count) 
    {
        size_t const SIZE_BIN{ static_cast<size_t>(row_count) };
        size_t const SIZE_S{ s.size() };
        vector<string> bin(SIZE_BIN, "");
        size_t i{ 0U };
        while(i < SIZE_S)
        {
            // ascend
            for(size_t j{ 0U }; i < SIZE_S && j < SIZE_BIN; ++j)
            {
                bin[j] += s[i];
                ++i;
            }
            // descend
            for(size_t j{ SIZE_BIN - 2 }; i < SIZE_S && j > 0 && j < SIZE_BIN; --j)
            {
                bin[j] += s[i];
                ++i;
            }
        }
        string ret;
        for(size_t i{ 0 }; i < SIZE_BIN; ++i)
        {
            ret += bin[i];
        }
        return ret;
    }
};