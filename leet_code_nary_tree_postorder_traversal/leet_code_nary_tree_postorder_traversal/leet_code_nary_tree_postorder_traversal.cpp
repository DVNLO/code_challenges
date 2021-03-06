/*
The following is a solution to leetcode prompt 590 N-ary Tree postorder 
traversal. 
Original prompt: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
Author: Dan Vyenielo
*/
#include "stdafx.h"
#include <vector>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	void postorder(vector<int>& log, Node const * const node)
	{
		if (!node)
			return;
		for (Node const * const child : node->children)
			postorder(log, child);
		log.push_back(node->val);
	}

	vector<int> postorder(Node* root) {
		vector<int> res;
		postorder(res, root);
		return res;
	}
};

int main()
{
    return 0;
}

