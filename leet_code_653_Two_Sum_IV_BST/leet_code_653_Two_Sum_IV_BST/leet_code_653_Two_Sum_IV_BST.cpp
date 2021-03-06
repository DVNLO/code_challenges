/*
The following is a solution to prompt 653. Two Sum IV - Input is a BST
from leetcode.com. I included two solutions. The first version
utilizes pre-order traversal to push each conjugate value into an
unordered_set<int>. Each new value is checked against the set 
of conjugates, and if the set contains that value we return true. 
In the second solution, we iterate through the BST via inorder
traversal to generate an ascending list of values. Then, we
traverse the list to find a pair that sums to K. The lower index
is incremented when the current sum is too small compared to the
target. The upper index is decremented when the current sum is too
large compared to the target. 
The prompt can be found here: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	/*//V1
	bool findTarget(TreeNode* root, int k) {
		stack<TreeNode*> nodes;
		nodes.emplace(root);
		unordered_set<int> conjugates;
		while(!nodes.empty()) { //pre-order traversal
			TreeNode* node = nodes.top();
			nodes.pop();
			int conjugate = k - node->val;
			if(conjugates.count(node->val))
				return true;
			else
				conjugates.emplace(conjugate);
			if(node->right != NULL) {
				nodes.emplace(node->right);
			}
			if(node->left != NULL){
				nodes.emplace(node->left);
			}
		}
		return false;
	}
	*/
	bool findTarget(TreeNode* root, int k) {
		std::stack<TreeNode*> nodes;
		std::vector<int> values;
		TreeNode* node = root;
		while (!nodes.empty() || node != NULL) { //inorder traversal
			if (node != NULL) {
				nodes.push(node);
				node = node->left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				values.push_back(node->val);
				node = node->right;
			}
		}

		for (int i = 0, j = values.size() - 1; i < j;) { //iterate through values
			int sum = values[i] + values[j];
			if (sum == k)
				return true;
			else if (sum > k)
				j--;
			else //(sum < k)
				i++;
		}
		return false;
	}
};

int main()
{
	Solution prompt;
	TreeNode root(5);
	TreeNode l(3);
	TreeNode ll(2);
	TreeNode lr(4);
	TreeNode r(6);
	TreeNode rr(7);
	root.left = &l;
	root.right = &r;
	l.left = &ll;
	l.right = &lr;
	r.right = &rr;
	prompt.findTarget(&root, 9);
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
