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
    // We can detect cycles in any data structure 
    // by traversing the data structure at fast and 
    // slow rates. In this example we maintain two pointers
    // one moving 2x the speed of the other. 
    bool hasCycle(ListNode *head) 
    {
        if(!head)
            return false;
        ListNode * slow{ head };
        ListNode * fast{ head };
        do
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }while(slow
                && fast
                && slow != fast);
        return slow != nullptr
                && fast != nullptr
                && slow == fast;
    }
};
