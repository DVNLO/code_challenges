/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // The following is my initial recursive solution. This made intuitive sense. 
    // The next step is to implement the iterative approach.
    TreeNode * generate_height_balanced_bst(vector<int> const & nums,
                                            vector<int>::const_iterator const left,
                                            vector<int>::const_iterator const right)
    {
        if(left >= right)
            return nullptr;
        vector<int>::const_iterator const midpoint{ left + (right - left) / 2 };
        TreeNode * root = new TreeNode(*midpoint);
        root->left = generate_height_balanced_bst(nums, left, midpoint);
        root->right = generate_height_balanced_bst(nums, midpoint + 1, right);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return generate_height_balanced_bst(nums, nums.begin(), nums.end());
    }
};
