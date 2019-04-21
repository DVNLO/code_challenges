/* The following is a solution to leetcode 1008 Construct Binary Search 
 * Tree from preorder traversal. The prompt can be found here:
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * No driver provided.
 */


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	void insert(TreeNode* root, TreeNode* node)
	{
		if (!root || !node)
		{
			return;
		}
		TreeNode* current = root;
		while (current)
		{
			root = current;
			if (node->val > current->val)
			{
				current = current->right;
			}
			else if (node->val < current->val)
			{
				current = current->left;
			}
		}
		if (node->val > root->val)
		{
			root->right = node;
		}
		else if (node->val < root->val)
		{
			root->left = node;
		}
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		size_t const size = preorder.size();
		if (!size)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode{ preorder[0] };
		if (size <= 1)
		{
			return root;
		}
		for (size_t i = 1; i < size; ++i)
		{
			TreeNode* T = new TreeNode{ preorder[i] };
			insert(root, T);
		}
		return root;
	}
};