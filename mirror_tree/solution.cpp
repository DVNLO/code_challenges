#include <bits/stdc++.h>
using namespace std;

struct node
{
    node * left{ nullptr };
    node * right{ nullptr };
    int val;
};

node *
generate_mirror_tree(node * const root)
{
    if(!root)
    {
        return nullptr;
    }
    node * const tmp{ root->right };
    root->right = generate_mirror_tree(root->left);
    root->left = generate_mirror_tree(tmp);
    return root;
}

vector<int>
traverse_inorder(node const * const root)
{
    if(!root)
    {
        return {}; 
    }
    else
    {
        vector<int> seq{ traverse_inorder(root->left) };
        seq.push_back(root->val);
        vector<int> tmp{ traverse_inorder(root->right) };
        seq.insert(end(seq), begin(tmp), end(tmp));
        return seq;
    }
}


// generates a mirror tree for the example tree provided
// at : https://practice.geeksforgeeks.org/problems/mirror-tree/1

int main()
{
    node * root = new node();
    root->val = 1;
    root->right = new node();
    root->right->val = 2;
    root->left = new node();
    root->left->val = 3;
    root->right->right = new node();
    root->right->right->val = 4;
    root->right->left = new node();
    root->right->left->val = 5;

    node * root_mirror_actual{ generate_mirror_tree(root) };
    
    node * root_mirror_expected = new node();
    root_mirror_expected->val = 1;
    root_mirror_expected->left = new node();
    root_mirror_expected->left->val = 2;
    root_mirror_expected->right = new node();
    root_mirror_expected->right->val = 3;
    root_mirror_expected->left->left = new node();
    root_mirror_expected->left->left->val = 4;
    root_mirror_expected->left->right = new node();
    root_mirror_expected->left->right->val = 5;

    vector<int> actual_inorder_seq{ traverse_inorder(root_mirror_actual) };
    vector<int> expected_inorder_seq{ traverse_inorder(root_mirror_expected) };
    if(actual_inorder_seq != expected_inorder_seq)
    {
        cout << "failure" << endl;
    }
    else
    {
        cout << "success" << endl;
    }
}

