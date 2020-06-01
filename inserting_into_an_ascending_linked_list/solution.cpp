#include <bits/stdc++.h>
using namespace std;

struct vertex
{
	int val;
	vertex * next;
};

vertex * build_list(int n)
{
	vertex * list{ nullptr };
	if(n < 1)
	{
		return nullptr;
	}
	list = new vertex;
	if(!list)
	{
		return nullptr;
	}
	vertex * cur{ nullptr };
	vertex * prev{ list };
	prev->val = 0;
	for(int i{ 1 }; i < n; ++i)
	{
		cur = new vertex;
		if(!cur)
		{
			return nullptr;
		}
		prev->next = cur;
		cur->val = i;
		prev = cur;
	}
	cur->next = nullptr;
	return list;
}

void print(vertex const * const list)
{
	vertex const * l{ list };
	while(l)
	{
		cout << l->val << ' ';
		l = l->next;
	}
}

vertex * insert(vertex * list, int val)
{
	vertex * l{ list };
	vertex * lv = new vertex;
	if(!lv)
	{
		// allocation failure
		return nullptr;
	}
	lv->val = val;
	if(!l)
	{
		// empty list
		lv->next = nullptr;
		return lv;
	}
	while(l->next 
		&& l->next->val < val)
	// Advace while there exists a vertex to advance too
	// and the value of the next vertex is less than the 
	// value being inserted.
	{
		l = l->next;
	}
	// Insert the vertex containing the value to insert
	// either at the end of the list or in the middle
	// and maintain the list's original ordering.
	lv->next = l->next;
	l->next = lv;
	return list;
}

int main()
{
	int n;
	cin >> n;
	vertex * list = build_list(n);
	print(list);
	cout << '\n';
	int v;
	cin >> v;
	list = insert(list, v);
	print(list);
	cout << '\n';
}
