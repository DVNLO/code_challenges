/*
The following is a solution to prompt 872. Leaf-Similar Trees from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/leaf-similar-trees/description/
The solution provides no trees with which to test the code. 
However, leetcode.com provides this service.
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		//non-empty root nodes assumed
		std::vector<int> leaf_sequence;
		std::stack<TreeNode*> nodes;
		nodes.push(root1);
		while (!nodes.empty()) {
			TreeNode* top = nodes.top();
			nodes.pop();
			if (top->left == NULL && top->right == NULL) {
				leaf_sequence.push_back(top->val);
				continue;
			}
			if (top->right != NULL)
				nodes.push(top->right);
			if (top->left != NULL)
				nodes.push(top->left);
		}
		int i = 0;
		nodes.push(root2);
		while (!nodes.empty()) {
			TreeNode* top = nodes.top();
			nodes.pop();
			if (top->left == NULL && top->right == NULL) {
				if (leaf_sequence[i] != top->val)
					return false;
				i++;
			}
			if (top->right != NULL)
				nodes.push(top->right);
			if (top->left != NULL)
				nodes.push(top->left);
		}
		return true;
	}
};


int main()
{
    return 0;
}

