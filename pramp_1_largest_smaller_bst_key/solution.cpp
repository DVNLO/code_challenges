#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	node * left{ nullptr };
	node * right{ nullptr };
};

void bst_insert(node * const root, 
		int val)
{
	if(!root)
		return;
	node * i{ new node };	// node to insert
	i->val = val;
	node * cur = root;
	while(cur)
	{
		if(i->val > cur->val)
		{
			if(cur->right)
				cur = cur->right;
			else
			{
				cur->right = i;
				break;
			}
		}
		else if(i->val < cur->val)
		{
			if(cur->left)
				cur = cur->left;
			else
			{
				cur->left = i;
				break;
			}
		}
		else	// don't bother inserting if there's a duplicate. Can setup to handle this error a better way later...
		{
			break;
		}
	}
}



node * const build_problem_tree()
{
	node * const root = new node;
	//root->val = 20;
	//pramp :: vector<int> vals{ 9, 25, 5, 12, 11, 14 };
	root->val = 25;
	vector<int> vals{ 2, 1, 3, 12, 9, 21, 19, 25 };
	for(auto const val : vals)
		bst_insert(root, val);
	return root;
}


void print_pre_order(node const * const root)
{
	if(!root)
		return;
	printf("%d ", root->val);
	print_pre_order(root->left);
	print_pre_order(root->right);
}

int find_largest_smaller_key(node const * const root, 
				int const num)
{
	// find the largest key in the tree that is smaller than num
	// max(N_l) < N < min(N_r) can I use this fact to narrow my search space?
	// let's implement the naieve approach first which doesn't leverage the BST nature of the tree and works in O(n) time
	// we do not need to traverse any of the tree greater than num. so 
	// 1. find the first node with a value less than num
	// 2. find the max node in that sub tree. 
	node const * cur{ root };
	while(cur && cur->val > num)	// find node with val less than num -> max 
					// value less than num must be an element 
					// of this sub tree
		cur = cur->left;
	while(cur)	// the max val is the rightmost value
	{
		if(cur->right 
			&& cur->right->val < num)
			cur = cur->right;
		else
			break;
	}
	if(!cur)
		return -1;
	else
		return cur->val;
}

int main()
{
	node * const root{ build_problem_tree() };
	//print_pre_order(root);
	//puts("");
	int n;
	scanf("%d", &n);
	int largest_smaller_key{ find_largest_smaller_key(root, n) };
	printf("%d ", largest_smaller_key);
}
