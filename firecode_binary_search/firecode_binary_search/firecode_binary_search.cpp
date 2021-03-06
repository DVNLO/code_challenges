#include "pch.h"
#include <iostream>

bool binary_search_do(int arr[], int size, int n) {
	int l = 0;  //left
	int r = size - 1;   //right
	int m;  //middle
	do {
		m = l + (r - l) / 2;    //prevent overflow
		if (arr[m] == n) {
			break;
		}
		else if (arr[m] < n) {    //go right
			l = m + 1;
		}
		else {  //go left
			r = m - 1;
		}
	} while (l <= r);
	return arr[m] == n;
}

bool binary_search_trad(int arr[], int size, int n) {
	int l = 0;  //left
	int r = size - 1;   //right
	int m = l + (r - l) / 2;//middle
	while(l < r){
		if (arr[m] == n) {
			break;
		}
		else if (arr[m] < n) {    //go right
			l = m + 1;
		}
		else {  //go left
			r = m - 1;
		}
		m = l + (r - l) / 2;	//prevent overflow
	}
	return arr[m] == n;
}

int main()
{
	const int size = 5;
	const int MAX_BOUNDRY = 9;
	int arr[size] = { 1, 3, 5, 7, 9 };
	for (int i = 0; i <= MAX_BOUNDRY; i++) {
		if (binary_search_trad(arr, size, i)) {
			std::cout << "true"; 
		}
		else {
			std::cout << "false";
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i <= MAX_BOUNDRY; i++) {
		if (binary_search_do(arr, size, i)) {
			std::cout << "true";
		}
		else {
			std::cout << "false";
		}
		std::cout << std::endl;
	}
}
