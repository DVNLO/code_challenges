/*
The following is a solution to leetcode prompt 559 max depth of  N-ary
tree. No driver is provided. The original prompt is available here:
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
Author: Dan Vyenielo
*/

#include "stdafx.h"
#include <algorithm>
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
	int maxDepth(Node const * const root, unsigned depth)
	{
		if (!root)
			return 0;
		int mxd = depth;
		for (Node const * const child : root->children)
			mxd = max(maxDepth(child, depth + 1), mxd);
		return mxd;
	}


	int maxDepth(Node* root) {
		return maxDepth(root, 1);
	}
};

int main()
{
    return 0;
}

