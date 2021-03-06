/*
The following is a solution to prompt 104. Maximum Depth of Binary Tree
from leetcode.com. The prompt can be found here:
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
As written, the following code will not invoke a solution object, but
can be compiled with leetcode.com's website. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

// leet_code_104_max_depth_binary_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <vector>

/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// This is my most recent solution to the same problem that 
// I solved a couple years ago. It's incredible how little 
// I understood recursion back then. I went as far to implement
// the iterative solution, which is much more difficult to implement.
// The iterative solution is more performant.
// I will conceed that using BFS is a slightly more intresting approach
// but it was not my initial response seeing the problem again. DFS
// follows for finding the depth more naturally. I did re-implement
// the BFS solution. 
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        return 1 + max(maxDepth(root->left), 
                       maxDepth(root->right));
    }
};


class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		std::stack<TreeNode*> nodes;
		nodes.push(root);
		int depth = 0;
		while (!nodes.empty()) {  //bredth-first search
			std::vector<TreeNode*> children(nodes.size());
			int i = 0;
			while (!nodes.empty()) {
				children[i] = nodes.top();
				nodes.pop();
				i++;
			}
			depth++;
			for (int i = 0; i < children.size(); i++) {
				TreeNode* child = children[i];
				if (child->right != NULL) {
					nodes.push(child->right);
				}
				if (child->left != NULL) {
					nodes.push(child->left);
				}
			}
		}
		return depth;
	}
};


int main()
{
    return 0;
}

