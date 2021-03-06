/*
The following is a solution to prompt 637. Average of Levels in Binary Tree
from leetcode.com. The prompt can be found here:
https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
Unfortunately, this code will not compile without their platform.
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
	std::vector<double> averageOfLevels(TreeNode* root) {
		std::vector<double> levelAverages;
		std::stack<TreeNode*> nodes;
		nodes.push(root);
		while (!nodes.empty()) {	//utilizing Breadth-first search
			std::vector<TreeNode*> levelNodes(nodes.size());
			int index = 0;
			while (!nodes.empty()) {
				levelNodes[index] = nodes.top();
				nodes.pop();
				index++;
			}
			double sum = 0;
			for (int i = 0; i < levelNodes.size(); i++) {
				TreeNode* node = levelNodes[i];
				sum += node->val;
				if (node->right != NULL) {
					nodes.push(node->right);
				}
				if (node->left != NULL) {
					nodes.push(node->left);
				}
			}
			levelAverages.push_back(sum / levelNodes.size());
		}
		return levelAverages;
	}
};


int main()
{
    return 0;
}

