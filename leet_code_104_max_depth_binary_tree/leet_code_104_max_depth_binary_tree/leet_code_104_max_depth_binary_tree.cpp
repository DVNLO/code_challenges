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

