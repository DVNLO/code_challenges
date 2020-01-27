class Solution {
public:
    /* Returns true if t is an anagram of s.
     * An anagram is a word, phrase, or name formed 
     * by rearranging the letters of another, such as
     * cinema, formed from iceman.
     */
    bool isAnagram(string s, 
                   string t) 
    {
        if(s.size() != t.size())
            return false;
        static size_t constexpr MAX_CHAR_COMBINATIONS{ static_cast<size_t>(256U) };
        unsigned symbol_counts[MAX_CHAR_COMBINATIONS];
        for(size_t i{ 0 }; i < MAX_CHAR_COMBINATIONS; ++i)
            symbol_counts[i] = 0U;
        for(auto const c : s)
            ++symbol_counts[static_cast<size_t>(c)];
        for(auto const c : t)
        {
            if(!symbol_counts[static_cast<size_t>(c)])
                return false;
            else
                --symbol_counts[static_cast<size_t>(c)];
        }
        for(size_t i{ 0 }; i < MAX_CHAR_COMBINATIONS; ++i)
        {
            if(symbol_counts[i])
                return false;
        }
        return true;
    }
};
