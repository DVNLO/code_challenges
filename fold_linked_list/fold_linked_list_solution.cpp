#include <iostream>

struct node
{
    int val;
    node * next;
};

void reverse(node *& head, int const size)
{
    if(size < 2)
        return;
    node * l = head;
    node * m = head->next;
    node * r = head->next->next;
    l->next = nullptr;
    while(r)
    {
        m->next = l;
        l = m;
        m = r;
        r = r->next;
    }
    m->next = l;
    head = m;
}

void fold_linked_list(node * head, int const size)
{
    if(size < 2)
        return;
    int midpoint{ size / 2 };
    node * prev = head;
    node * cur = head->next;
    for(int i{ 1 }; i < midpoint; ++i)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;
    reverse(cur, size - midpoint);
    node * left = head;
    node * left_next = head->next;
    node * right = cur;
    node * right_next = right->next;
    while(left_next)
    {
        left->next = right;
        right->next = left_next;
        left = left_next;
        right = right_next;
        left_next = left_next->next;
        right_next = right_next->next;
    }
    left->next = right;
}

void print(node * head)
{
    using namespace std;
    while(head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int const SIZE{ 6 };
    node * head = new node;
    int i{ 1 };
    head->val = i;
    ++i;
    node * cur = head;
    while(i <= SIZE)
    {
        cur->next = new node;
        cur = cur->next;
        cur->val = i;
        ++i;
    }
    cur->next = nullptr;
    print(head);
    fold_linked_list(head, SIZE);
    print(head);
}
