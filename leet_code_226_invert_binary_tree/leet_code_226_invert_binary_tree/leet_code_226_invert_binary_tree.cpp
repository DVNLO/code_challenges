/*
The following is a solution to prompt 226. Invert Binary Tree from
leetcode.com. The prompt can be found here: https://leetcode.com/problems/invert-binary-tree/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <stack>

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		std::stack<TreeNode*> nodes;
		nodes.push(root);
		while (!nodes.empty()) {
			TreeNode* top = nodes.top();
			nodes.pop();
			TreeNode* swap = top->right;
			top->right = top->left;
			top->left = swap;
			if (top->right != NULL) {
				nodes.push(top->right);
			}
			if (top->left != NULL) {
				nodes.push(top->left);
			}
		}
		return root;
	}
};


int main()
{
	

	TreeNode* root = new TreeNode(4);
		
	TreeNode* l = new TreeNode(2);
	TreeNode* ll = new TreeNode(1);
	TreeNode* lr = new TreeNode(3);

	TreeNode* r = new TreeNode(7);
	TreeNode* rl = new TreeNode(6);
	TreeNode* rr = new TreeNode(9);

	root->left = l;
	root->right = r;

	l->left = ll;
	l->right = lr;

	r->left = rl;
	r->right = rr;

	/*
	Input:
		 4
	   /   \
	  2     7
	 / \   / \
	1   3 6   9
	*/

	Solution prompt;
	prompt.invertTree(root);

	/*
	Output:
		 4
	   /   \
	  7     2
	 / \   / \
	9   6 3   1
	*/

	delete root;
	delete l;
	delete ll;
	delete lr;
	delete r;
	delete rl;
	delete rr;

    return 0;
}

