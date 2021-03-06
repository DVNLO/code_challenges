/*
The following is a solution to prompt 654. Maximum Binary Tree from 
leetcode.com. The original prompt can be found here:
https://leetcode.com/problems/maximum-binary-tree/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

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
	typedef vector<int>::const_iterator vici;
public:
	TreeNode* construct(vector<int>& nums, const vici left, const vici right) {
		if (left >= right)
			return nullptr;
		vici max = left;
		vici iter = left;
		while (iter < right) {
			if (*iter > *max)
				max = iter;
			iter++;
		}
		TreeNode* root = new TreeNode(*max);
		root->left = construct(nums, left, max);
		root->right = construct(nums, max + 1, right);
		return root;
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return construct(nums, nums.begin(), nums.end());
	}
};

void delete_tree(TreeNode* root) {
	if (!root) {
		return;
	}
	delete_tree(root->left);
	delete_tree(root->right);
	cout << root->val << endl;
	delete root;
}

int main()
{
	vector<int> vec = {3,2,1,6,0,5};
	Solution prompt;
	TreeNode* root = prompt.constructMaximumBinaryTree(vec);
	delete_tree(root);
}