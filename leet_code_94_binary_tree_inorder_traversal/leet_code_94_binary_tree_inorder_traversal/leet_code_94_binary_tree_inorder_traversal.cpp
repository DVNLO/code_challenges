/*
The following is are solutions to prompt 94. Binary Tree Inorder Traversal
from leetcode.com. An iterative and recursive solution are included.
The prompt can be found here: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<int> vals;

	std::vector<int> inorderTraversal_recur(TreeNode* root) {
		if (root != NULL) {
			if (root->left != NULL) {
				inorderTraversal_recur(root->left);
			}
			vals.push_back(root->val);
			if (root->right != NULL) {
				inorderTraversal_recur(root->right);
			}
		}
		return vals;
	}


	std::vector<int> inorderTraversal_iter(TreeNode* root) {
		std::stack<TreeNode*> nodes;
		std::vector<int> vals;
		TreeNode* node = root;
		while (!nodes.empty() || node != NULL) {
			if (node != NULL) {
				nodes.push(node);
				node = node->left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				vals.push_back(node->val);
				node = node->right;
			}
		}
		return vals;
	}
};

int main()
{
	Solution prompt;
	TreeNode root(5);
	TreeNode l(3);
	TreeNode ll(2);
	TreeNode lr(4);
	TreeNode r(6);
	TreeNode rr(7);
	root.left = &l;
	root.right = &r;
	l.left = &ll;
	l.right = &lr;
	r.right = &rr;
	
	std::vector<int> vals_iter = prompt.inorderTraversal_iter(&root);
	std::vector<int> vals_recur = prompt.inorderTraversal_recur(&root);
	for (int i = 0; i < vals_iter.size(); i++)
	{
		std::cout << vals_iter[i] << " | " << vals_recur[i] << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
