/*
The following are solutions to prompt 701 insert into BST from leetcode.com
(https://leetcode.com/problems/insert-into-a-binary-search-tree/). Note: I have 
not included a driver. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "pch.h"
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void binary_search_to_insert(TreeNode* root, const int& val) {
		if (val > root->val) {    //check right
			if (root->right) //go right
				binary_search_to_insert(root->right, val);
			else {    //insert value
				root->right = new TreeNode(val);
			}
		}
		else {  //check left
			if (root->left)  //go left
				binary_search_to_insert(root->left, val);
			else {    //insert value
				root->left = new TreeNode(val);
			}
		}
	}

	TreeNode* insertIntoBST_first(TreeNode* root, int val) {
		binary_search_to_insert(root, val);
		return root;
	}

	TreeNode* insertIntoBST_second(TreeNode* root, int val) {
		if (!root) {
			return new TreeNode(val);
		}
		if (val < root->val) {   //try left
			root->left = insertIntoBST_second(root->left, val);
		}
		else {  //try right
			root->right = insertIntoBST_second(root->right, val);
		}
		return root;
	}

	TreeNode* insertIntoBST_iter(TreeNode* root, int val) {
		TreeNode* tail;
		TreeNode* head = root;
		while (head) {
			tail = head;
			if (val < head->val)
				head = head->left;
			else
				head = head->right;
		}
		TreeNode* node = new TreeNode(val);
		if (val < tail->val)
			tail->left = node;
		else
			tail->right = node;
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
