/*The following program is intended for use with hackerrank's prompt, and
requires a tree signiture string to be passed in, for an already existing 
hoffman tree. https://www.hackerrank.com/challenges/tree-huffman-decoding
Author: Dan Vyenielo
Date 9/29/17
*/
/*
The structure of the node is

typedef struct node
{
int freq;
char data;
node * left;
node * right;

}node;

*/


void decode_huff(node * root, string s)
{
	node* head = root;
	for (unsigned int i = 0; i < s.size(); i++) {
		//cout << "Enter: " << "i = " << i << " S[i] = " << s[i] << '\n';
		if (root->right != nullptr && s[i] == '1') {
			root = root->right; //move right
								//cout << "move right\n";
		}
		if (root->left != nullptr && s[i] == '0') {
			root = root->left;  //move left
								//cout << "move left\n";
		}
		if (root->left == nullptr && root->right == nullptr) {    //at a leaf
			cout << root->data;
			root = head;    //return to the head
		}
		//cout << "Exit: " << "i = " << i << " S[i] = " << s[i] << '\n';   
	}
}
