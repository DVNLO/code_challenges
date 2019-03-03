/* The following is a solution to leetcode prompt 429 N-ary Tree level order 
 * traversal. I have implemented an iterative solution using the STL queue
 * to store Node* and iterate on each level. The size of the queue, before
 * visiting a level determines the number of nodes to visit, on that level.
 * The original prompt: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 * Author: Dan Vyeniel
 */

#include <queue>
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
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        if(!root)
            return levels;
        queue<Node*> nodes;
        nodes.push(root);
        unsigned level_node_count;
        while(!nodes.empty())
        {
            level_node_count = nodes.size();
            vector<int> level;
            while(level_node_count)
            {
                Node* current = nodes.front();
                nodes.pop();
                level.push_back(current->val);
                for(Node* child : current->children)
                    nodes.push(child);
                --level_node_count;
            }
            levels.push_back(level);
        }
        return levels;
    }
};

int main()
{
}
