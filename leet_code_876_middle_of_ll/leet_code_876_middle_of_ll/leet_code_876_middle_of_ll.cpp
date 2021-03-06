/*
The following is a solution to prompt 876. Middle of the Linked List
from leetcode.com. I have included two solutions, one solution is my own
the other is from the leetcode website. My solution iterates through
the list counting the number of nodes. We count from 1 so that the
return node in an even elemented list will return the latter middle node.
The websites solution is very elegant, and performs less computations.
Try to employ thought more similar to their solution. The prompt can be found 
here: https://leetcode.com/problems/middle-of-the-linked-list/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "pch.h"
#include <iostream>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* middleNode_v1(ListNode* head) {
		ListNode* node = head;
		int node_count = 1; //index from 1 to return second middle node
		while (node->next != NULL) {
			node_count++;
			node = node->next;
		}
		int i = node_count / 2;
		node = head;
		while (i != 0) {
			i--;
			node = node->next;
		}
		return node;
	}

	/*
	A fundamentally more interesting approach to finding the solution.
	If we move one pointer slow and another pointer fast, such that
	the fast pointer moves 2x as fast as the slow pointer, then when the
	fast pointer is at the end the slow pointer will be at the middle.
	Solution found here: https://leetcode.com/articles/middle-of-the-linked-list/
	*/
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};


int main()
{
	ListNode one(1);
	ListNode two(2);
	ListNode three(3);
	ListNode four(4);
	ListNode five(5);
	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	Solution prompt;
	prompt.middleNode(&one);
	prompt.middleNode_v1(&one);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
