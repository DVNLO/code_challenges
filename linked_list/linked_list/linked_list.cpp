// linked_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct Node
{
	int data;
	Node* next;
};

class ll
{
public:
	ll();
	~ll();
	void add(int value);

private:
	Node* head;
	Node* tail;
};

ll::ll()
{
	head = nullptr;
	tail = nullptr;
}

ll::~ll()
{
}

void ll::add(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = nullptr;
	
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail = temp;
	}
}


int main()
{
	ll myList; 
	myList.add(1);
	myList.add(2);
	return 0;
}

