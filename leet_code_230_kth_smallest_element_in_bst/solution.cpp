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
    
    void inorder_traverse_to_find_kth_smallest(TreeNode * root,
                                                int const k, 
                                                int & i,
                                                int &ret_val,
                                                bool & found)
    {
        if(!root || found)
            return;
        inorder_traverse_to_find_kth_smallest(root->left, k, i, ret_val, found);
        ++i;
        if(i == k)
        {
            ret_val = root->val;
            found = true;
            return;
        }
        inorder_traverse_to_find_kth_smallest(root->right, k, i, ret_val, found);
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int i{ 0 };
        int ret_val;
        bool found{ false };
        inorder_traverse_to_find_kth_smallest(root, k, i, ret_val, found);
        return ret_val;
    }
};
