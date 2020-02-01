// The following is decent code. It's not the most performant. 
// There seems to be an alternative algorithm which is much faster
// rather than the recursive approach. For example, 
// when I build a truth table I can enumerate all the permutations
// of n bits in a systematic way, when i have 3 elements
// that systematic approach is still valid. However, it explores
// a very large search space. There seems to be something here
// that might help change the algorithm for this problem.

class Solution {
public:
    void permute(vector<int> & vals,
                 vector<int> & permutation,
                 size_t const permutation_idx,
                 vector<vector<int>> & permutations)
    {
        size_t const vals_size{ vals.size() };
        if(!vals_size)
        {
            permutations.emplace_back(permutation);
            return;
        }
        size_t const sub_problem_vals_size{ vals_size - 1 };
        vector<int> sub_problem_vals(sub_problem_vals_size);
        if(permutation_idx >= permutation.size())
            permutation.resize(permutation_idx + 1);
        size_t k;
        for(size_t i{ 0 }; i < vals_size; ++i)
        {
            k = 0;
            for(size_t j{ 0 }; j < sub_problem_vals_size; ++j)
            {
                if(i == j)
                    ++k; 
                sub_problem_vals[j] = vals[k];
                ++k;
            }
            permutation[permutation_idx] = vals[i];
            permute(sub_problem_vals, permutation, permutation_idx + 1, permutations);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> permutations;
        vector<int> permutation;
        permute(nums, permutation, 0, permutations);
        return permutations;
    }
};
