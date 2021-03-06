/*
The following is a solution to prompt 617 Merge Binary Trees from leetcode.com
(https://leetcode.com/problems/merge-two-binary-trees/). I have provided my 
intuited solution. Note, that this program does not provide a driver. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1 && !t2)
			return nullptr;
		if (!t1) {
			return t2;
		}
		if (!t2) {
			return t1;
		}
		TreeNode* root = new TreeNode(0);
		if (t1) {
			root->val += t1->val;
		}
		if (t2) {
			root->val += t2->val;
		}
		root->left = mergeTrees(t1->left, t2->left);
		root->right = mergeTrees(t1->right, t2->right);
		return root;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}