
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	node* left{nullptr};
	node* right{nullptr};
	int val;
};

int isPresent(node* root, int val) {
	if (!root)
		return 0;
	else if (root->val == val)
		return 1;
	else if (root->val > val)
		isPresent(root->left, val);
	else if (root->val < val)
		isPresent(root->right, val);
}

void problem_1() {
	node root;
	root.val = 20;
	node l;
	l.val = 10;
	node r;
	r.val = 30;
	node ll;
	ll.val = 2;
	node lr;
	lr.val = 12;
	node rl;
	rl.val = 25;
	node rr;
	rr.val = 35;
	root.left = &l;
	root.right = &r;
	l.left = &ll;
	l.right = &lr;
	r.left = &rl;
	r.right = &rr;
	const int ARRAY_SIZE = 8;
	int arr[ARRAY_SIZE] = { 20, 10, 2, 12, 30, 25, 35, 8 };
	int i = 0;
	while (i < ARRAY_SIZE) {
		std::cout << isPresent(&root, arr[i]);
		i++;
	}
}

int max_difference(const vector<int>& a) {
	const int size = a.size();
	if (size < 2) {
		return -1;
	}
	int max_difference = -1;
	for (int j = 1; j < size; j++) {
		int tmp_difference = - 1;
		for (int i = 0; i < j; i++) {
			if (a[i] < a[j] && a[j] - a[i] > tmp_difference)
				tmp_difference = a[j] - a[i];
		}
		if (tmp_difference > max_difference)
			max_difference = tmp_difference;
	}
	return max_difference;
}

void problem_2() {
	vector<int> a = { 1, 2, 3, 4, 5, 6, 7 };
	std::cout << max_difference(a);
}

int main()
{
	problem_1();
	problem_2();
}