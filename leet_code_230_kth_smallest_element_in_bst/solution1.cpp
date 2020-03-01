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
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int ret_val;
        int i{ 0 };
        stack<TreeNode *> s;
        s.push(root);
        TreeNode * cur{ root };
        while(cur 
              || !s.empty())
        {
            if(!cur)
            {
                cur = s.top();
                s.pop();
                ++i;
                if(i == k)
                {
                    ret_val = cur->val;
                    break;
                }
                cur = cur->right;
            }
            else
            {
                s.push(cur);
                cur = cur->left;
            }
        }
        return ret_val;
    }
};
