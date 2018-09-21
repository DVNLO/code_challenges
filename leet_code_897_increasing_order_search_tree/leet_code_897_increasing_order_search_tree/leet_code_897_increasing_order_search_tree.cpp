/*
The following is a solution to prompt 897 Increasing Order Search Tree
from leetcode.com. The program first finds the left most node by traversing
the tree exclusively left, and simultanesouly building a stack of visted 
nodes. The left most node is assigned as the new root from the top of the stack.
The program enters an iterative inorder traversal of the constructed stack
with tail and node pointers null. As the tree is traversed tail points to 
the ending node of the ordered list. For each visited node tail->right is updated
to point to the current node, node. The function returns a TreeNode* to
the list's root node. 
Author: Dan Vyenilo (dvyenielo@gmail.com)
*/

#include "pch.h"
#include <iostream>
#include <stack>

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*
	Transforms a stack of nodes to the next state, in place.
	Considers the top node root. Returns the nodes stack with 
	next node on top.
	*/
	void next(std::stack<TreeNode*>& nodes) {
		TreeNode* root = nodes.top();
		nodes.pop();
		if (root->left) {
			root = root->left;
			nodes.push(root);
			while (root->left) {
				root = root->left;
				nodes.push(root);
			}
		}
		else if (root->right) {
			root = root->right;
			nodes.push(root);
			while (root->left) {
				root = root->left;
				nodes.push(root);
			}
		}
	}

	TreeNode* increasingBST(TreeNode* root) {
		if (!root)
			return root;
		std::stack<TreeNode*> nodes;
		while (root) {
			nodes.push(root);
			root = root->left;
		}
		root = nodes.top();	//left most node is new root
		TreeNode* tail = root;
		next(nodes);
		TreeNode* node = NULL;
		while (!nodes.empty() || node) { //inorder traversal
			if (node) {
				nodes.push(node);
				node = node->left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				tail->right = node;
				node->left = NULL;
				tail = node;
				node = node->right;
			}
		}
		return root;
	}
};

int main()
{
	TreeNode root(5);
	TreeNode l(3);
	TreeNode lr(4);
	TreeNode ll(2);
	TreeNode lll(1);
	TreeNode r(6);
	TreeNode rr(8);
	TreeNode rl(7);
	TreeNode rrr(9);
	
	root.left = &l;
	l.left = &ll;
	l.right = &lr;
	ll.left = &lll;
	root.right = &r;
	r.right = &rr;
	rr.left = &rl;
	rr.right = &rrr;

	Solution prompt;
	TreeNode* root_ptr = prompt.increasingBST(&root);
	while (root_ptr->right) {
		root_ptr = root_ptr->right;
		std::cout << root_ptr->val << " ";
	}
	std::cout << "\n";
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
