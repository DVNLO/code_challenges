/*
The following are solutions to problem 965 Univalued Binary Tree from 
leetcode.com. Note that no driver is provided. A driver is provided by 
by leetcode on the accompanying webpage (https://leetcode.com/problems/univalued-binary-tree/). 
Author: Dan Vyenielo
*/
#include "pch.h"
#include <iostream>
#include <stack>

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
//#######################################################
	//second solution
	/*
	Notice how we can utilize short circuit evaluation to our advantage here.
	*/
	bool isUnivalTree(TreeNode* root, const int& value) {
		if (!root)
			return true;
		if (root->val != value)
			return false;
		return isUnivalTree(root->left, value) && isUnivalTree(root->right, value);
	}

	bool isUnivalTree(TreeNode* root) {
		return isUnivalTree(root->left, root->val) && isUnivalTree(root->right, root->val);
	}
//#######################################################

	bool isUnivalTree_first_attempt(TreeNode* root) {
		const int value = root->val;
		std::stack<TreeNode*> nodes;
		TreeNode* node;
		nodes.push(root);
		while (!nodes.empty()) {
			node = nodes.top();
			nodes.pop();
			if (node->val != value)
				return false;
			if (node->right)
				nodes.push(node->right);
			if (node->left)
				nodes.push(node->left);
		}
		return true;
	}
};


int main()
{
    std::cout << "Hello World!\n"; 
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
