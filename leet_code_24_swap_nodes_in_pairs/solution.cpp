// I'm getting quite a bit of mileage out of this dummy head
// trick that I learned about in leet code 20. Very helpful 
// in this problem. 
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
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head)
        {
            return head;
        }
        ListNode * dh{ new ListNode };  // dummy head
        dh->next = head;
        ListNode * h{ dh };
        ListNode * l{ h->next };
        ListNode * r{ l->next };
        if(!r)
        {
            delete dh;
            return head;
        }
        ListNode * t{ r->next };
        // initial condition : h -> l -> r -> t
        while(h)
        {
            r->next = l;
            l->next = t;
            h->next = r;
            h = l;
            l = h->next;
            if(!l)
            {
                break;
            }
            r = l->next;
            if(!r)
            {
                break;
            }
            t = r->next;
        }
        head = dh->next;
        delete dh;
        return head;
    }
};
