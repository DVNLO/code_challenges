// Here is the file binarytree.cpp

#include "stdafx.h"
#include <iostream>
#include "binarytree.h"
using namespace std;



binarytree::binarytree() {
	root = nullptr;
	mSize = 0;
}

void binarytree::print() {
	print_aux(root);
}


void binarytree::insert(int item) {
	mSize++;
	insert_aux(root, item);
}

binarytree::size_type binarytree::size() {
	return mSize;
}


int binarytree::find(int target, bool& found) {
	return find_aux(root, target, found);
}


void binarytree::del(int target, bool& found) {
	mSize--;
	del_aux(root, target, found);
}



binarytree::binarytree(binarytree &item) {
	if (item.root == NULL)
		root = NULL;
	else
		copyBinaryTree(this->root, item.root);
}





void copyBinaryTree(binarytree::treenode*& otherRoot, binarytree::treenode*& mainRoot) {
	if (mainRoot == NULL)
	{
		otherRoot = NULL;
	}
	else
	{
		otherRoot = new binarytree::treenode;
		otherRoot->data = mainRoot->data;
		copyBinaryTree(otherRoot->left, mainRoot->left);
		copyBinaryTree(otherRoot->right, mainRoot->right);
	}
}




binarytree::~binarytree(){
	clearBinaryTree(this->root);
}




void clearBinaryTree(binarytree::treenode* root) {
	if (root != NULL) {
		clearBinaryTree(root->right);
		clearBinaryTree(root->left);
		delete root;
	}
}



binarytree binarytree::operator=(binarytree& copy) {
	if (this->root != copy.root) {
		copyBinaryTree(this->root, copy.root);
	}
	mSize = copy.mSize;
	return *this;
}




/*
cs_ll::LL<int> binarytree::toLL() {
cs_ll::LL<int> list;
toLL_aux(root, list);
return list;
}
*/




/*
void toLL_aux(binarytree::treenode*& root, cs_ll::LL<int>& list) {


}
*/



int binarytree::numPrimes() {
	return numPrimes_aux(root);
}




int numPrimes_aux(binarytree::treenode*& root) {
	if (root == nullptr ) {
		return 0;
	}
	else {
		if (isPrime(root->data, root->data - 1)) {
			return numPrimes_aux(root->left) + numPrimes_aux(root->right) + 1;
		}
		else {
			return  numPrimes_aux(root->left) + numPrimes_aux(root->right);
		}
	}
}

bool isPrime(int i, int k) {
	if (i <= 1) {
		return false;
	}
	if (k == 1)
		return true;
	else {
		if (i % k== 0) {
			return false;
		}
		else
			return isPrime(i, k - 1);
	}
}



void del_aux(binarytree::treenode*& root,
	int target,
	bool& found) {

	if (root == nullptr) {
		found = false;
	}
	else if (target < root->data) {
		del_aux(root->left, target, found);
	}
	else if (target > root->data) {
		del_aux(root->right, target, found);
	}
	else if (root->left == nullptr) {
		binarytree::treenode* tempptr = root;
		root = root->right;
		delete tempptr;
		found = true;
	}
	else {
		int max;
		remove_max(root->left, max);
		root->data = max;
		found = true;
	}
}

// pre: root != nullptr

void remove_max(binarytree::treenode*& root, int& max) {
	if (root->right == nullptr) {
		max = root->data;
		binarytree::treenode* tempptr = root;
		root = root->left;
		delete tempptr;
	}
	else {
		remove_max(root->right, max);
	}
}




int find_aux(binarytree::treenode* root,
	int target,
	bool& found) {

	if (root == nullptr) {
		found = false;
		return 0;
	}
	else if (target == root->data) {
		found = true;
		return root->data;
	}
	else if (target < root->data) {
		return find_aux(root->left, target, found);
	}
	else {
		return find_aux(root->right, target, found);
	}
}





void insert_aux(binarytree::treenode*& root, int item) {
	if (root == nullptr) {
		// root = new treenode(item, nullptr, nullptr);
		root = new binarytree::treenode;
		root->data = item;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (item <= root->data) {
		insert_aux(root->left, item);
	}
	else {
		insert_aux(root->right, item);
	}
}


void print_aux(binarytree::treenode* root) {
	if (root != nullptr) {
		print_aux(root->left);
		cout << root->data << " ";
		print_aux(root->right);
	}
}
