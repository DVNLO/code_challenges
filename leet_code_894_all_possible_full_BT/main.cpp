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

void buildFBTS(vector<TreeNode*> & trees, TreeNode*& cur_tree_root, TreeNode*& cur_node,
		unsigned cur_size, unsigned const target_size)
{
	if(!cur_node->left && !cur_node->right)
	{
		cur_node->left = new TreeNode(0);
		cur_node->right = new TreeNode(0);
		cur_size += 2;
	}
	if(cur_size == target_size)
	{
		trees.push_back(copy(cur_tree_root));
		return;
	}
	if(cur_node->left)
		buildFBTS(trees, copy(cur_tree_root), cur_node->left, cur_size, target_size);
	if(cur_node->right)
		buildFBTS(trees, copy(cur_tree_root), cur_node->right, cur_size, target_size);
}


vector<TreeNode*> allPossibleFBT(int N)
{
	vector<TreeNode*> trees;
	if(!(N % 2))
		return trees;
	TreeNode* root = new TreeNode(0);
	buildFBTS(trees, root, 1, N);
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

