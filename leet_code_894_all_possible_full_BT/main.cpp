#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void appendChildren(TreeNode*& node)
{
	node->left = new TreeNode(0);
	node->right = new TreeNode(0);
}

/* Returns a copy of the source binary tree. Only extant nodes on the source
 * tree are visited.
 */
TreeNode* copy(TreeNode const * const source)
{
	if(!source)
		return nullptr;
	TreeNode* root = new TreeNode(source->val);
	if(source->left)
		root->left = copy(source->left);
	if(source->right)
		root->right = copy(source->right);
	return root;
}

vector<TreeNode*> allPossibleFBT(int N)
{
	vector<TreeNode*> trees;
	if(N <= 0 || !(N % 2))
		return trees;
	TreeNode* tree = new TreeNode(0);
	appendChildren(tree);
	//buildCompleteTrees(trees, N);
	return trees;
}

TreeNode* build_test_tree()
{
	TreeNode* two = new TreeNode(2);
	TreeNode* one = new TreeNode(1);
	TreeNode* three = new TreeNode(3);
	two->left = one;
	two->right = three;
	return two;
}

int main()
{
	TreeNode* test = build_test_tree();
	copy(nullptr);
	TreeNode* test_copy = copy(test);
	if(&*test == &*test_copy)
		cout << "equal\n";
	else
		cout << "not equal\n";

}

