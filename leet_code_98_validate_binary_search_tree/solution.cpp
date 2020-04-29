// The following are two solutions to the validation of a binary search tree
// problem on leetcode, one is iterative and the last is recusive. The recursive
// solution was much harder to think of. I fumbled with how to backtrack
// the information through the call stack, but once I realized that I could
// feed the current node's value forward it was equivalent and maintained
// the binary search tree invariant. 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    
    bool isValidBST(TreeNode* root) 
    {
        stack<TreeNode*> s;
        TreeNode * cur{ root };
        TreeNode * min{ nullptr };
        while(!s.empty() || cur)
        {
            if(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = s.top();
                s.pop();
                if(min && min->val >= cur->val)
                    return false;
                else
                    min = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};

class Solution1 {
public:
    bool is_valid_bst(TreeNode * root, TreeNode * min, TreeNode * max)
    {
        if(!root)
            return true;
        if((min && min->val >= root->val)
           || (max && max->val <= root->val))
        {
            return false;
        }
        else
        {
            return is_valid_bst(root->left, min, root)
                    && is_valid_bst(root->right, root, max);
        }
    }


    bool isValidBST(TreeNode* root)
    {
        return is_valid_bst(root, nullptr, nullptr);
    }
};
