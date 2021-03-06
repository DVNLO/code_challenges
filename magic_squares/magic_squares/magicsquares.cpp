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
	/*cout << "Begin check " << square << endl;
	cout << "Center is 5" << endl;
	cout << "Sum row 1: " << (uint_fast64_t(square[0]) + uint_fast64_t(square[1]) + uint_fast64_t(square[2])) << endl;
	cout << "Sum row 2: " << (uint_fast64_t(square[3]) + uint_fast64_t(square[4]) + uint_fast64_t(square[5])) << endl;
	cout << "Sum row 3: " << (uint_fast64_t(square[6]) + uint_fast64_t(square[7]) + uint_fast64_t(square[8])) << endl;
	cout << "Sum column 1: " << (uint_fast64_t(square[0]) + uint_fast64_t(square[3]) + uint_fast64_t(square[6])) << endl;
	cout << "Sum column 2: " << (uint_fast64_t(square[1]) + uint_fast64_t(square[4]) + uint_fast64_t(square[7])) << endl;
	cout << "Sum column 3: " << (uint_fast64_t(square[2]) + uint_fast64_t(square[5]) + uint_fast64_t(square[8])) << endl;
	cout << "Sum diagonal forward: " << (uint_fast64_t(square[0]) + uint_fast64_t(square[4]) + uint_fast64_t(square[8])) << endl;
	cout << "Sum diagonal backward: " << (uint_fast64_t(square[2]) + uint_fast64_t(square[4]) + uint_fast64_t(square[6])) << endl;
*/
	short int i = 0, k = 0;
	while (i < 9)
	{
		k += i;
		while (k < 9)
		{
			if (square[i] == square[k])
			{
				return false;
			}
			k++;
		}
		i++;
	}

	auto magic_sum = (uint_fast64_t(square[0]) + uint_fast64_t(square[1]) + uint_fast64_t(square[2]));

	return (
		//sum of rows
		(
			((uint_fast64_t(square[3]) + uint_fast64_t(square[4]) + uint_fast64_t(square[5])) == magic_sum) &&
			((uint_fast64_t(square[6]) + uint_fast64_t(square[7]) + uint_fast64_t(square[8])) == magic_sum)
		) &&
		//sum of columns
		(
			((uint_fast64_t(square[0]) + uint_fast64_t(square[3]) + uint_fast64_t(square[6])) == magic_sum) &&
			((uint_fast64_t(square[1]) + uint_fast64_t(square[4]) + uint_fast64_t(square[7])) == magic_sum) &&
			((uint_fast64_t(square[2]) + uint_fast64_t(square[5]) + uint_fast64_t(square[8])) == magic_sum)
		) &&
		//diagonals
		(
			((uint_fast64_t(square[0]) + uint_fast64_t(square[4]) + uint_fast64_t(square[8])) == magic_sum) &&
			((uint_fast64_t(square[2]) + uint_fast64_t(square[4]) + uint_fast64_t(square[6])) == magic_sum)
		)
	);
}

// this generates all possible combinations 
// of 1-9 digits that may or may not 
// form a magic square
static string buffer = "000000000";
static string magic_string = "816357492";
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
