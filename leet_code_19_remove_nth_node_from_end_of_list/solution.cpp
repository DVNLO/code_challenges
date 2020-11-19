/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd_initial_implementation(ListNode* head, int n) 
    {
        std::stack<ListNode *> s;
        ListNode * cur{ head };
        while(cur)
        {
            s.push(cur);
            cur = cur->next;
        }
        for(int i{ 0 }; i < n; ++i)
        {
            cur = s.top();
            s.pop();
        }
        if(!s.empty())
        {
            s.top()->next = cur->next;
        }
        else
        {
            head = cur->next;
        }
        delete cur;
        return head;
    }
};
