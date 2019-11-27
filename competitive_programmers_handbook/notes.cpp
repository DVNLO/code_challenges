#include <bits/stdc++.h>	// g++ include entire standard C++ library.
				// so we  can focus on the code rather than the explicitly
				// necessary headers for our program.

using namespace std;	// use standard library namespace by default.

int main()
{
	
	ios::sync_with_stdio(0);	// prevent I/O bottlenecking program.
	cin.tie(0);			// 
	
	// prefer input with cin, generally easier to interface with than scanf.
	// may prefer printf for printing when precise precision is required.
	
	string s;
	getline(cin, s);	// read one line fron cin into s.

	// alternatively when the number of data to read is unknown
	while(cin >> s)
	{
		// do
	}	// this will consume all data from the input.

	// int is 32 bit [-2^31 : 2^31 - 1] or about [-2*10^9 : 2*10^9]
	// long long is 64 bit [-2^63 : 2^63 - 1] or about [-9*10^18 : 9*10^18]
	// we can initialize a long long variable like
	long long a = 123LL;	// LL suffix specifies the long long nature of the literal

	// it can be challenging to infer the implicit type conversions when working
	// with combinations of types. Try to keep consistency whenever possible.
	
	// MODULAR ARITHMETIC
	// x % m will not always return a value [0 : (m - 1)] as we anticipate in math
	// we can write a function to handle the case where m can be negative. 
	// I explore the implementation of positive modulo in another module
	// This section is incredibly insightful and covers the method for computing the 
	// modulo of large numbers and states a few equivalences of modulo operations
	// number addition, subtraction, and multiplications, mainly:
	// 1) (a + b) mod c == ((a mod c) + (b mod c)) mod c
	// 2) (a - b) mod c == ((a mod c) - (b mod c)) mod c
	// 3) (a * b) mod c == ((a mod c) * (b mod c)) mod c
	// These equalities allow us to substiture these operationns when numbers maybe
	// come increasingly large. For example, the handbook presents computation
	// of n! mod m as:
	int i = 1;
	for(int j = 2; j <= n; ++j)
		i = (i * j) % m; 
	cout << i % m << '\n';

	//FLOTING POINT NUMBERS
	// The equality of floting point numbers can be difficult to establish due to
	// precision issues in the binary represenstaion of our base 10 decimal value.
	// Using the equality operator with FP can produce unanticipated results, so 
	// to establish equality we tpically determine an error window epsilon 
	// arround which we consider two FP values to be equal. Eg: we can consider
	// two FP vals X and Y equal by:
	if(abs(X - Y) < 1e-9)
		// they're equal because they have difference less than epsilon. 
	
	// MACROS
	// perform pattern string matching substitution per-compilation with the pre-processor
	

	return 0;
}
