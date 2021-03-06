/*
The following are my solutions for string reversal.
Author: Dan Vyenielo(dvyenielo@gmail.com)
*/

#include "pch.h"
#include <iostream>
#include <stack>

void string_reverse1(char* string)	//reverse in place
{
	int j = 0;
	while (string[j] != '\0') {
		j++;
	}
	j--;
	int i = 0;
	char tmp;
	while (i < j) {
		tmp = string[i];
		string[i] = string[j];
		string[j] = tmp;
		i++;
		j--;
	}
}

char* string_reverse2(const char* string)
{
	int j = 0;
	while (string[j] != '\0') {
		j++;
	}
	char* res = new char[j + 1];
	res[j] = '\0';
	j--;
	int i = 0;
	while (i <= j) {
		res[j] = string[i];
		res[i] = string[j];
		i++;
		j--;
	}
	return res;
}

int main()
{
	//char message[9] = { '!', 'e', 'm', ' ', 'e', 'r', 'i', 'h', '\0' };
	char odd[] = { 'a', 'b', 'c', 'd', 'e', '\0' };
	char even[] = { 'a', 'b', 'c', 'd', '\0' };
	string_reverse1(odd);
	printf(odd);
	int i = 0;
	char* res = string_reverse2(even);
	printf(res);
	delete[] res;
	i++;
}