// fibonacci_128_int.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>


int main()
{
	__int128 fn1 = 1;
	__int128 fn2 = 2;
	__int128 fn3 = 0;
	while (fn3 = fn1 + fn2)
	{
		std::printf(fn3);
		fn1 = fn2;
		fn2 = fn3;
	}
	return 0;
}

