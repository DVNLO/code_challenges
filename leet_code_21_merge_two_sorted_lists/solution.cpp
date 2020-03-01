// This took me a while to solve. The break through observation
// came when I realized that maintaining only a single pointer
// to the lhs and rhs lists was necessary, and the "new" list
// I was creating could be formed by selecting a node from 
// the lhs XOR the rhs at every iteration. After iterating,
// there maybe either remaining nodes on lhs XOR rhs so 
// we append those in the final step before returning the head.
// The prelude code determining the head isn't necessary,
// but it helped me through the initial understanding of how 
// to manipulate the lists. Other people showed that we could allocate
// a dummy node, but that's additional unecessary work that
// I didn't think was reasonable.
//
// One visual crutch that I think helped while solving this
// was the idea that two strings are being tied together
// at the cur pointer.

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
    
    
    ListNode* mergeTwoLists(ListNode* lhs, ListNode* rhs) 
    {
        if(!lhs)
            return rhs;
        if(!rhs)
            return lhs;
        ListNode * head;
        if(lhs->val <= rhs->val)
        {
            head = lhs;
            lhs = lhs->next;
        }
        else
        {
            head = rhs;
            rhs = rhs->next;
        }
        ListNode * cur{ head };
        while(lhs && rhs)
        {
            if(lhs->val <= rhs->val)
            {
                cur->next = lhs;
                cur = cur->next;
                lhs = lhs->next;
            }
            else
            {
                cur->next = rhs;
                cur = cur->next;
                rhs = rhs->next;
            }
        }
        if(lhs)
            cur->next = lhs;
        if(rhs)
            cur->next = rhs;
        return head;
    }
};
