#include <bits/stdc++.h>
using namespace std;

struct node
{
	node * next;
	int val;
};

node * build_linked_list(int const node_count)
{
	if(!node_count)
		return nullptr;
	node * head{ new node };
	head->val = 0;
	node * cur{ head }; 
	for(int i{ 1 }; i < node_count; ++i)
	{
		cur->next = new node;
		cur = cur->next;
		cur->val = i;
	}
	cur->next = nullptr;
	return head;
}

node * reverse_linked_list(node * head)
{
	node * l{ head };	// left
	node * m{ head->next };	// middle
	if(!m)
		return l;
	node * r{ head->next->next};	// right
	l->next = nullptr;
	while(r)
	{
		m->next = l;
		l = m;
		m = r;
		r = r->next;
	}
	m->next = l;
	l = m;
	return l;
}

void print_linked_list(node * head)
{
	while(head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
}
		
int main()
{
	int n;
	scanf("%d", &n);
	node * head_forward{ build_linked_list(n) };
	print_linked_list(head_forward);
	puts("");
	node * head_reverse{ reverse_linked_list(head_forward) };
	print_linked_list(head_reverse);
}
