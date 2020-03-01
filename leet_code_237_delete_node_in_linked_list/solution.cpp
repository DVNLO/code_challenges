// This is what I would label a "bad" interview question. The solution
// hinges on recognizing that we can simply copy the next value
// into the node that we have been given access too.
// And, it's not even capable of deleting nodes in all edge cases. 
// For example if node == tail, then we can't do this.. 
// Garbage problem teaching bad coding practices.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode * next = node->next;
        if(!next)
            return;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};
