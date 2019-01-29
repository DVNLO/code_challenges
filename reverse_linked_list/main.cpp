#include <iostream>

struct Node
{
	int data;
	Node* next;
};

Node* build_list(int const size)
{
	if(size <= 0)
		return nullptr;
	Node* head = new Node{ 0, nullptr };
	Node* previous = head;
	Node* current = nullptr;
	for(int i = 1; i < size; ++i)
	{
		current = new Node { i , nullptr};
		previous->next = current;
		previous = current;
	}
	return head;
}

void print_list(Node const * head)
{
	while(head)
	{
		std::cout << head->data << ' ';
		head = head->next;
	}
}

void reverse_list(Node*& head)
{
	if(!head)
		return;
	Node* f = head;	// front
	Node* m = f->next;	// middle
	if(!m)
		return;	// single element list is reversed
	Node* l = m->next;	// last
	f->next = nullptr;
	while(l)
	{
		m->next = f;
		f = m;
		m = l;
		l = l->next;
	}
	m->next = f;
	head = m;
}


int main()
{
	for(int i = 0; i <= 10; ++i)
	{
		Node* head = build_list(i);
		print_list(head);
		std::cout << '\n';
		reverse_list(head);
		print_list(head);
		std::cout << '\n';
		std::cout << '\n';
	}
}
