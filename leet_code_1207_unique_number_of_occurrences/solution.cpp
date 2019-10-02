/* The following is a solution to leetcode prompt 1207 Unique number of 
 * occurences. The prompt can be found here: 
 * https://leetcode.com/problems/unique-number-of-occurrences/
 * No driver is provided.
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        std::unordered_map<int, int> occurence_counts;
        for(auto const val : arr)
        {
            if(occurence_counts.count(val))
            {
                ++occurence_counts[val];
            }
            else
            {
                occurence_counts[val] = 1;
            }
        }
        std::unordered_set<int> unique_counts;
        for(auto const pair : occurence_counts)
        {
            if(unique_counts.count(pair.second))
            {
                return false;
            }
            else
            {
                unique_counts.insert(pair.second);
            }
        }
        return true;
    }
};
