class Solution {
public:
    
    inline int alpha_to_val(char const c)
    {
        return (c - 'A' + 1);
    }
    
    int titleToNumber(string s) 
    {
        size_t const S_SIZE{ s.size() };
        if(!S_SIZE)
            return 0;   // error.
        int col_num{ 0 };
        int base{ 1 };
        for(size_t i{ S_SIZE - 1}; i; --i)
        {
            col_num += alpha_to_val(s[i]) * base;
            base *= 26;
        }
        col_num += alpha_to_val(s[0]) * base;
        return col_num;
    }
};
