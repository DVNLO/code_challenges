/* The following is a solution to leetcode prompt 1161 Maximum Level Sum of Binary Tree.
 * The original prompt can be found https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
 * No drive is provided.
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
    void bfs_to_find_max_level_sum(std::queue<TreeNode *> & level_nodes,
                                   int current_level,
                                   int & max_level,
                                   int & max_sum)
    {
        if(level_nodes.empty())
        {
            return;
        }
        std::queue<TreeNode *> next_level_nodes;
        int level_sum = 0;
        while(!level_nodes.empty())
        {
            TreeNode * node = level_nodes.front();
            level_nodes.pop();
            level_sum += node->val;
            if(node->left)
            {
                next_level_nodes.push(node->left);
            }
            if(node->right)
            {
                next_level_nodes.push(node->right);
            }
        }
        if(level_sum > max_sum)
        {
            max_sum = level_sum;
            max_level = current_level;
        }
        bfs_to_find_max_level_sum(next_level_nodes,
                                  ++current_level,
                                  max_level,
                                  max_sum);
    }

    int maxLevelSum(TreeNode* root) {
        if(!root)
        {
            return -1;
        }
        std::queue<TreeNode *> level_nodes;
        level_nodes.push(root);
        int max_level{ 1 };
        int max_sum{ root->val };
        bfs_to_find_max_level_sum(level_nodes, 1, max_level, max_sum);
        return max_level;
    }
};
