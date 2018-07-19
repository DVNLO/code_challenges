// Here is the file binarytree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstdlib>	// for size_t
#include "ll.h"
class binarytree {

public:
	typedef std::size_t size_type;
	binarytree();
	void insert(int item);
	void print();
	size_type size();
	int find(int target, bool& found);
	void del(int target, bool& found);
	int numPrimes();
	//cs_ll::LL<int> toLL();
	binarytree(binarytree &item);
	~binarytree();
	binarytree operator=(binarytree& copy);
	
private:
	struct treenode {
		int data;
		treenode* left;
		treenode* right;
	};

	size_type mSize;
	treenode* root;
	//friend functions need prototype declarations outside the class
	friend void copyBinaryTree(treenode*& otheRroot, treenode*& maiNroot);
	friend void insert_aux(treenode*& root, int item);
	friend void print_aux(treenode* root);
	friend int find_aux(treenode* root, int target, bool& found);
	friend void del_aux(treenode*& root, int target, bool& found);
	friend void remove_max(treenode*& root, int& max);
	friend bool isPrime(int n, int k);
	friend int numPrimes_aux(treenode*& root);

	//friend void toLL_aux(treenode*& root, cs_ll::LL<int>& list);
	friend void clearBinaryTree(treenode* root);
};

bool isPrime(int n, int k);

#endif
