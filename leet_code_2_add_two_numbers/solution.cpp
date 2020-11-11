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
class Initial_Solution {
public:
    ListNode* addTwoNumbers(ListNode* lhs, ListNode* rhs) 
    {
        ListNode * ret = new ListNode;
        ListNode * cur_lhs{ lhs };
        ListNode * cur_rhs{ rhs };
        ListNode * cur_ret{ ret };
        int carry{ 0 };
        while(cur_lhs && cur_rhs)
        {
            cur_ret->next = new ListNode;
            cur_ret = cur_ret->next;
            int tmp = cur_lhs->val + cur_rhs->val + carry;
            cur_ret->val = tmp % 10;
            carry = tmp / 10;
            cur_lhs = cur_lhs->next;
            cur_rhs = cur_rhs->next;
        }
        while(cur_lhs)
        {
            cur_ret->next = new ListNode;
            cur_ret = cur_ret->next;
            int tmp = cur_lhs->val + carry;
            cur_ret->val = tmp % 10;
            carry = tmp / 10;
            cur_lhs = cur_lhs->next;
        }
        while(cur_rhs)
        {
            cur_ret->next = new ListNode;
            cur_ret = cur_ret->next;
            int tmp = cur_rhs->val + carry;
            cur_ret->val = tmp % 10;
            carry = tmp / 10;
            cur_rhs = cur_rhs->next;
        }
        if(carry)
        {
            cur_ret->next = new ListNode;
            cur_ret = cur_ret->next;
            cur_ret->val = carry;
        }
        cur_ret->next = nullptr;
        ret = ret->next;
        return ret;
    }
};

class ConciseSolution {
public:
    ListNode* addTwoNumbers(ListNode* lhs, ListNode* rhs)
    {
        ListNode * ret = new ListNode;
        ListNode * cur_lhs{ lhs };
        ListNode * cur_rhs{ rhs };
        ListNode * cur_ret{ ret };
        int carry{ 0 };
        while(cur_lhs || cur_rhs)
        {
            ListNode * cur = new ListNode;
            int tmp{ carry };
            if(cur_lhs)
            {
                tmp += cur_lhs->val;
                cur_lhs = cur_lhs->next;
            }
            if(cur_rhs)
            {
                tmp += cur_rhs->val;
                cur_rhs = cur_rhs->next;
            }
            cur->val = tmp % 10;
            carry = tmp / 10;
            cur_ret->next = cur;
            cur_ret = cur_ret->next;
        }
        if(carry)
        {
            cur_ret->next = new ListNode;
            cur_ret = cur_ret->next;
            cur_ret->val = carry;
        }
        cur_ret->next = nullptr;
        ret = ret->next;
        return ret;
    }
};
