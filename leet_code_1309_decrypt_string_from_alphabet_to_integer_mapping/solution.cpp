class Solution 
{
public:
    string freqAlphabets(string s) 
    {
        size_t const SIZE_S{ s.size() };
        size_t pound_count{ 0U };
        for(size_t i{ 0 }; i < SIZE_S; ++i)
        {
            if(s[i] == '#')
                ++pound_count;
        }
        size_t const SIZE_RET{ SIZE_S - 2 * pound_count };
        size_t const END{ std::numeric_limits<size_t>::max() };
        std::string ret(SIZE_RET, '0');
        size_t j{ SIZE_RET - 1 };
        std::string tmp;
        for(size_t i{ SIZE_S - 1}; i < END;)
        {
            if(s[i] == '#')
            {
		// assumes no '#' occurs within 2 of the start of array
		// assumption safe by problem statment.
                tmp = s.substr(i - 2, 2);
                i -= 3;
            }
            else
            {
                tmp = s[i];
                --i;
            }
	    // narrowing conversion guarenteed safe by problem statement.
            ret[j] = 'a' + (static_cast<unsigned char>(stoul(tmp)) - 1);
            --j;
        }
        return ret;
    }
};
