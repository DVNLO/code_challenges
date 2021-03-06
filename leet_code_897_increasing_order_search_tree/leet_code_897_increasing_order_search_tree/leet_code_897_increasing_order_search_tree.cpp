/*
The following are solutions to prompt 897 Increasing Order Search Tree
from leetcode.com. Each solution has an accompanying description.
Original prompt: https://leetcode.com/problems/increasing-order-search-tree/description/
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

	//76 percentile
	/*
	For a non-NULL root node, transform the BST into an 
	increasing list of tree nodes. 
	Note: by reducing comparison statements total number 
	of instructions can be minimized.
	*/
	TreeNode* increasingBST_3(TreeNode* root) {
		if (!root)
			return root;
		std::stack<TreeNode*> nodes;
		while (root->left) {	//traverse to the left-most node
			nodes.push(root);	//stores nodes along the path
			root = root->left;  
		}
		TreeNode* node = root;	//left most node is new root
		TreeNode* tail = NULL;
		while (!nodes.empty() || node) { //inorder traversal
			if (node) {
				nodes.push(node);
				node = node->left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				if (tail) {
					tail->right = node;
					node->left = NULL;
				}
				tail = node;
				node = node->right;
			}
		}
		return root;
	}
	
	//39 percentile
	TreeNode* increasingBST_2(TreeNode* root) {
		if (root == NULL)
			return root;
		std::stack<TreeNode*> nodes;
		while (root->left != NULL) {
			nodes.push(root);
			root = root->left;  //left most node is new root
		}
		TreeNode* node = root;
		TreeNode* tail = NULL;
		while (!nodes.empty() || node != NULL) { //inorder traversal
			if (node != NULL) {
				nodes.push(node);
				node = node->left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				if (tail != NULL) {
					tail->right = node;
					node->left = NULL;
				}
				tail = node;
				node = node->right;
			}
		}
		return root;
	}
	
	//30 percentile
	TreeNode* increasingBST_1(TreeNode* root) {
		if (root == NULL)
			return root;
		std::stack<TreeNode*> nodes;
		TreeNode* node = root;
		while (root->left != NULL)
			root = root->left;  //left most node is root
		TreeNode* tail = NULL;
		while (!nodes.empty() || node != NULL) { //inorder traversal
			if (node != NULL) {
				nodes.push(node);
				node = node->left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				if (tail != NULL) {
					tail->right = node;
					node->left = NULL;
				}
				if (node != NULL)
					tail = node;
				node = node->right;
			}
		}
		return root;
	}
	
	//55 percentile
	TreeNode* increasingBST_0(TreeNode* root) {
		if (root == NULL)
			return root;
		std::stack<TreeNode*> nodes;
		TreeNode* node = root;
		while (root->left != NULL)   //dig left to find the new root
			root = root->left;
		TreeNode* previous = NULL;
		while (!nodes.empty() || node != NULL) { //inorder traversal
			if (node != NULL) {
				nodes.push(node);
				node = node->left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				if (previous != NULL) {
					previous->right = node;
					node->left = NULL;
				}
				previous = node;
				node = node->right;
			}
		}
		return root;
	}
	
	/*
	Transforms a stack of nodes to the next state, in place.
	Considers the top node root. Returns the nodes stack with 
	next node on top. Does not visit root node.
	*/
	void next_stack_state(std::stack<TreeNode*>& nodes) {
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

	//71 percentile
	/*
	This function differs from the others, by moving the state of
	the stack forward by one node after finding the new root (left-most node).
	By moving to the next state, node can be assigned to the next node 
	during the first iteration of the inorder traversal, reducing a
	conditional statement in the else clause (compared fo other functions above).
	In effect, node will be NULL or one node ahead of tail at all times.
	*/
	TreeNode* increasingBST(TreeNode* root) {
		if (!root)
			return root;
		std::stack<TreeNode*> nodes;
		while (root->left) {
			nodes.push(root);
			root = root->left;	//root is left-most node
		}
		nodes.push(root);
		TreeNode* tail = root;
		next_stack_state(nodes);
		TreeNode* node = NULL;
		while (!nodes.empty() || node) { //inorder traversal
			if (node) {
				nodes.push(node);
				node = node->left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				tail->right = node;	//no need for conditional statement as we enter in next stack state
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
