


class Solution {
public:
    
    array<unsigned, 256> generate_symbol_counts(string const s)
    {
        array<unsigned, 256> sym_counts{ 0 };
        for(size_t i{ 0 }; i < 256; ++i)
        {
            ++sym_counts[s[i]];
        }
        return sym_counts;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> anagram_groups;
        size_t const STRS_SIZE{ strs.size() };
        for(size_t i{ 0 }; i < STRS_SIZE; ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            anagram_groups[s].emplace_back(strs[i]);
        }
        vector<vector<string>> grouped_anagrams(anagram_groups.size());
        size_t i{ 0 };
        for(auto const & anagram_group : anagram_groups)
        {
            grouped_anagrams[i] = anagram_group.second;
            ++i;
        }
        return grouped_anagrams;
    }
};


// The following was my initial solution. It timedout, becaue
// its an O(n^2) approach. 

class Solution {
public:
    
    bool is_anagram(string const & lhs, string const & rhs)
    {
        unsigned sym_counts[256]{ 0 };
        size_t const LHS_SIZE{ lhs.size() };
        for(size_t i{ 0 }; i < LHS_SIZE; ++i)
        {
            ++sym_counts[lhs[i]];
        }
        size_t const RHS_SIZE{ rhs.size() };
        for(size_t i{ 0 }; i < RHS_SIZE; ++i)
        {
            --sym_counts[rhs[i]];
        }
        for(size_t i{ 0 }; i < 256; ++i)
        {
            if(sym_counts[i] != 0U)
                return false;
        }
        return true;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> anagram_groups;
        size_t const STRS_SIZE{ strs.size() };
        vector<bool> found_anagram(STRS_SIZE, false);
        vector<string> anagram_group;
        size_t i{ 0 };
        while(i < STRS_SIZE)
        {
            anagram_group.emplace_back(strs[i]);
            found_anagram[i] = true;
            for(size_t j{ i + 1 }; j < STRS_SIZE; ++j)
            {
                if(is_anagram(strs[i], strs[j]))
                {
                    found_anagram[j] = true;
                    anagram_group.emplace_back(strs[j]);
                }
            }
            anagram_groups.emplace_back(anagram_group);
            anagram_group.clear();
            while(i < STRS_SIZE
                  && found_anagram[i])
            {
                ++i;
            }
        }
        return anagram_groups;
    }
};
