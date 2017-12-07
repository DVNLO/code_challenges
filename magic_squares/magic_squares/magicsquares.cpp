/*
	The following is an implementation of magic squares inspired
	by the prompt "propose a function that tells if a 3x3 square 
	written as an ASCII string of digits is magic or not in the 
	most effective manner." (http://wordsandbuttons.online/challenge_your_performance_intuition_with_cpp_magic_squares.html).
	check_if_magic() is my implementation.
	7 December 2017 | Dan Vyenielo
	*/
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <string>

using namespace std;

// Here you should implement your 
// magic checker. It should return 
// true if the square is magic, 
// false otherwise.
//
//                8 1 6    this is
// "816357492" =  3 5 7    a magic
//                4 9 2    square
//
bool check_if_magic(const std::string& square)
{
	return (square[4] == 5);
	
	return (
		//sum of rows
		((square[0] + square[1] + square[2]) ==
			(square[3] + square[4] + square[5]) ==
			(square[6] + square[7] + square[8])) &&
		//sum of columns
		((square[0] + square[3] + square[6]) ==
			(square[1] + square[4] + square[7]) ==
			(square[2] + square[5] + square[8])) &&
		//diagonals
		((square[0] + square[4] + square[8]) ==
			(square[2] + square[4] + square[6]))
		);
}

// this generates all possible combinations 
// of 1-9 digits that may or may not 
// form a magic square
static string buffer = "000000000";
void generate_or_check(int index_or_check = 8)
{
	if (index_or_check == -1) {
		if (check_if_magic(buffer))
			cout << buffer << " ";
		return;
	}

	for (auto i = 1u; i < 10; ++i) {
		buffer[index_or_check] = '0' + i;
		generate_or_check(index_or_check - 1);
	}
}

// this runs the generator and measures time
int main()
{
	auto start = std::chrono::system_clock::now();
	generate_or_check();
	auto end = std::chrono::system_clock::now();
	chrono::duration<double>
		difference = end - start;
	cout << difference.count() << "\n\n";
}
