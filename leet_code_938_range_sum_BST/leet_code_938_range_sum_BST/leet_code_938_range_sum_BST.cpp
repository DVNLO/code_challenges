/*
The following is a solution to prompt 938 range sum BST from leetcode.com. The
prompt can be found here:
https://leetcode.com/problems/range-sum-of-bst/
Note: No driver is provided.
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
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (!root)
			return 0;
		int sum = rangeSumBST(root->left, L, R);
		sum += rangeSumBST(root->right, L, R);
		if (root->val >= L && root->val <= R)
			sum += root->val;
		return sum;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}