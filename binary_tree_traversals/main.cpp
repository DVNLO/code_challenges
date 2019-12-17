#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val{ 0 };
    node * left{ nullptr };
    node * right{ nullptr };
};

node * build_tree(int n)
{
    node * root = new node;
    queue<node *> nodes;
    nodes.push(root);
    int i{ 1 };
    while(i < n)
    {
        node * cur = nodes.front();
        nodes.pop();
        cur->left = new node;
        cur->left->val = i;
        ++i;
        nodes.push(cur->left);
        if(i >= n)
            break;
        cur->right = new node;
        cur->right->val = i;
        ++i;
        nodes.push(cur->right);
    }
    return root;
}

void print(node * root)
{
    queue<node *> nodes;
    nodes.push(root);
    while(!nodes.empty())
    {
        node * cur = nodes.front();
        nodes.pop();
        cout << cur->val << ' ';
        if(cur->left)
            nodes.push(cur->left);
        if(cur->right)
            nodes.push(cur->right);
    }
    cout << endl;
}

void iterative_preorder_traversal(node * root)
{
    if(!root)
        return;
    node * cur;
    stack<node *> nodes;
    nodes.push(root);
    while(!nodes.empty())
    {
        cur = nodes.top();
        nodes.pop();
        cout << cur->val << ' ';
        if(cur->right)
            nodes.push(cur->right);
        if(cur->left)
            nodes.push(cur->left);
    }
    cout << endl;
}

void iterative_inorder_traversal(node * root)
{
    if(!root)
        return;
    node * cur{ root };
    stack<node *> nodes;
    while(cur || !nodes.empty())
    {
        if(cur)
        {
            nodes.push(cur);
            cur = cur->left;
        }
        else    // !cur
        {
            cur = nodes.top();
            nodes.pop();
            cout << cur->val << ' ';    // visit
            cur = cur->right;
        }
    }
    cout << endl;
}


void iterative_postorder_traversal(node * root)
{
    if(!root)
        return;
    stack<node *> nodes;
    node * prev{ nullptr };
    node * cur{ root };
    while(!nodes.empty() || cur)
    {
        if(cur)
        {
            nodes.push(cur);
            cur = cur->left;
        }
        else    // !cur
        {
            node * top{ nodes.top() };
            if(top->right && prev != top->right)
                cur = top->right;
            else
            {
                cout << top->val << ' ';    // visit
                prev = top;
                nodes.pop();
            }
        }
    }
    cout << endl;
}

int main()
{
    // building the tree:
    node * root{ build_tree(5) };
    print(root);
    iterative_preorder_traversal(root);
    iterative_inorder_traversal(root);
    iterative_postorder_traversal(root);
}
