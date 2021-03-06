// insertion_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

template<typename T>
void insertion_sort_ascending(T& list, const int size) {
	for (int j = 1; j < size; j++) {
		int key = list[j];
		int i = j - 1;
		while (i >= 0 && list[i] > key) {
			list[i + 1] = list[i];
			i--;
		}
		list[i + 1] = key;
	}
}

template<typename T>
void insertion_sort_decending(T& list, const int size) {
	for (int j = 1; j < size; j++) {
		int key = list[j];
		int i = j - 1;
		while (i >= 0 && list[i] < key) {
			list[i + 1] = list[i];
			i--;
		}
		list[i + 1] = key;
	}
}

void print(const std::vector<int>& list, const int size) {
	if (size > 0) {
		std::cout << list[0];
		for (int i = 1; i < size; i++) {
			std::cout << ' ' << list[i];
		}
		std::cout << '\n';
	}
}

int main()
{
	std::vector<int> list = { 5, 5, 6, 7, 9, 4, 3, 1, 2 };
	print(list, list.size());
	insertion_sort_ascending(list, list.size());
	print(list, list.size());
	insertion_sort_decending(list, list.size());
	print(list, list.size());
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
