/* The following is a solution to leeetcode prompt 1160 Find Words that can be 
 * Formed by Chars. The original prompt can be found here:
 * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/ 
 */

/* This is my first solution. It was not accepted due to the time complexity
 * of generating all permutations of the chars. 
 */
class Solution {
public:
    void form_all_permutations(std::string const & chars, 
                               std::string const & current_str,
                               std::unordered_set<std::string> & permutations)
    {
        if(!permutations.count(current_str))
        {
            permutations.insert(current_str);
        }
        std::size_t SIZE{ chars.size() };
        for(std::size_t i = 0; i < SIZE; ++i)
        {
            std::string next_str{ current_str + chars[i] };
            std::string next_chars{ chars };
            next_chars.erase(i, 1);
            form_all_permutations(next_chars, next_str, permutations);
        }
    }
    
    int countCharacters(vector<string>& words, string chars) {
        std::unordered_set<std::string> words_set{ words.begin(), words.end() };
        std::unordered_set<std::string> permutations;
        std::string current_str;
        form_all_permutations(chars, current_str, permutations);
        int length_sum{ 0 };
        for(std::string const & permutation : permutations)
        {
            if(words_set.count(permutation))
            {
                length_sum += permutation.size();
            }
        }
        return length_sum;
    }
};

/* This is my second solution. It wasn't very performat due to the copy
 * requirement of the char to count map in can_spell(...). However, it
 * is a workable solution.
 */
class Solution {
public:
    std::unordered_map<char, std::size_t> build_char_to_count_map(std::string const & chars)
    {
        std::unordered_map<char, std::size_t> char_to_count_map;
        for(char const c : chars)
        {
            if(!char_to_count_map.count(c))
            {
                char_to_count_map[c] = static_cast<std::size_t>(1);
            }
            else
            {
                ++char_to_count_map[c];
            }
        }
        return char_to_count_map;
    }
    
    bool can_spell(std::string const & word, std::unordered_map<char, std::size_t> char_to_count_map)
    {
        for(char const c : word)
        {
            if(!char_to_count_map.count(c) || !char_to_count_map[c])
            {
                return false;
            }
            else
            {
                --char_to_count_map[c];
            }
        }
        return true;
    }
    
    int countCharacters(vector<string>& words, string chars) 
    {
        std::unordered_map<char, std::size_t> char_to_count_map{ build_char_to_count_map(chars) };
        std::size_t WORD_COUNT{ words.size() };
        int length_sum{ 0 };
        for(std::size_t i = 0; i < WORD_COUNT; ++i)
        {
            if(can_spell(words[i], char_to_count_map))
            {
                length_sum += words[i].size();
            }
        }
        return length_sum;
    }
};
