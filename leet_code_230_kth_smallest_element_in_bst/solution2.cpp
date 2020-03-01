// On my third solution I noticed that I could change the
// order of the branching and thought that it might be faster.
// It was, and it clocked in 99% for runtime and 93% for memory.
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
            if(cur)
            {
                s.emplace(cur);
                cur = cur->left;
            }
            else
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
        }
        return ret_val;
    }
};
