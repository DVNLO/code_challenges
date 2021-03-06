// leet_code_my_circular_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class MyCircularQueue {
private:
	int* values;
	int size;
	int* head;
	int* tail;

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		values = new int[k];
		size = k;
		head = NULL;
		tail = NULL;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			head = values;
			tail = values;
		}
		else if (tail + 1 > (values + size - 1)) {
			tail = values;  //roll to the front
		}
		else {
			tail++;
		}
		*tail = value;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty()) {
			return false;
		}
		if (tail == head) {
			tail = NULL;
			head == NULL;
		}
		else if (tail - 1 < values) {
			tail = values + size - 1;   //roll to the end
		}
		else {
			tail--;
		}
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		return *(head);
	}

	/** Get the last item from the queue. */
	int Rear() {
		return *(tail);
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return head == NULL && tail == NULL;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return (tail + 1 == head) ||
			((head == values) && (tail == (values + size - 1)));
	}

	~MyCircularQueue()
	{
		delete[] values;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

int main()
{
	MyCircularQueue dan(5);
	dan.enQueue(1);
	dan.enQueue(2);
	dan.enQueue(3);
	dan.enQueue(4);
	dan.enQueue(5);
    std::cout << "Hello World!\n"; 
	dan.isFull();
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
