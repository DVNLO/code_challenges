/* The following is a solution to leetcode prompt 1078 Occurences after
 * Bigram. A "Bigram" is defined as a sequence of consecutive values. In 
 * this prompt the Bigram is the concatentation of the first and second
 * string arguments. A drive for this solution is not provided. The 
 * original prompt can be found at: https://leetcode.com/problems/occurrences-after-bigram/
 */
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) 
    {
        std::vector<string> occurences;
        stringstream ss{ text };
        std::string first_read;
        ss >> first_read;
        std::string second_read;
        while(!ss.eof())
        {
            ss >> second_read;
            if(first == first_read && second == second_read)
            {
                std::string occurence;
                ss >> occurence;
                if(!occurence.empty())
                {
                    occurences.push_back(occurence);
                }
                first_read = occurence;
            }
            else
            {
                first_read = second_read;    
            }
        }
       return std::move<>(occurences); 
    }
};
