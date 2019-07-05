/* The following is a solution to leetcode prompt 1038 Binary Search Tree
 * to Greater Search Tree. My Solution was accepted on the first attempt
 * :)! The solution uses recursion to iterate Right-Node-Left while 
 * maintaining a sum of the tree. 
 */

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
    void bstToGst(TreeNode* root, int& sum)
    {
        if(!root)
        {
            return;
        }
        if(root->right)
        {
            bstToGst(root->right, sum);
        }
        sum += root->val;
        root->val = sum;
        if(root->left)
        {
            bstToGst(root->left, sum);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) 
    {
        int sum = 0;
        bstToGst(root, sum);
        return root;        
    }
};
