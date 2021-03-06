/*The following are solutions to prompt 814 Binary Tree Pruning from 
leetcode.com (https://leetcode.com/problems/binary-tree-pruning/).
pruneTree_WO_help(...) implements pruning in terms of itself through
assignments to left and right children. pruneTree_W_help(...) implements the
same functionality, but is more performant. Both functions iterate through
the binary tree in post-order. A node is pruned from the tree when both 
children are nullptr's and it's data is null. Note, the potential memory
leak in both functions after assignment of the root pointer. A discussion 
thread post on leetcode made a good case for why we should allow this leak. He
argued that delete is only necessary with new and delete coupling. Since we did
not allocate the memory, it's not our responsibility to clean it up. Now, in 
my current state this sounds acceptable, but may not be the case in other 
organizations. Although, it's a decent argument imo.
Here is the discussion thread: https://leetcode.com/problems/binary-tree-pruning/discuss/122730/C%2B%2BJavaPython-Self-Explaining-Solution-and-2-lines
Author: Dan Vyenielo (dvyenielo@gmail.com)
Note: I have not provided a driver for this program.
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
	TreeNode* pruneTree_WO_help(TreeNode* root) {
		if (!root)
			return nullptr;
		root->left = pruneTree_WO_help(root->left);
		root->right = pruneTree_WO_help(root->right);
		if (!root->val && !root->right && !root->left)
			root = nullptr;	//note the potential memory leak
		return root;
	}

	void postorder_traverse(TreeNode*& root) {
		if (!root)
			return;
		postorder_traverse(root->left);
		postorder_traverse(root->right);
		if (!root->val && !root->left && !root->right) {
			root = NULL;
		}
	}

	TreeNode* pruneTree_W_help(TreeNode* root) {
		postorder_traverse(root);
		return root;
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
