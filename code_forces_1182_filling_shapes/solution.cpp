#include <bits/stdc++.h>
using namespace std;

int ways_initial_recursive_soln(int const n)
{
	if(n <= 1)
	{
		return 0;
	}
	if(n == 2)
	{
		return 2;
	}
	else if(n & 0x1)
	{
		return ways_initial_recursive_soln(n + 1);
	}
	else // n > 1 && n is even
	{
		return 2 * ways_initial_recursive_soln(n - 2);
	}
}

// I made a mistake when reading the prompt. I need to read these
// more closely. Take time to understand before moving on. Go slower
// during comprehension. The mistake I made was missing that 
// only full configurations are acceptable. Meaning if n is odd
// that it is not possible to produce a full configuration so 
// there are 0 ways. Otherwise, there are 2 ^ n / 2 ways. This
// is because there are two ways to arrange the first two and
// the remaining sub problem. Just like my initial recurrence.
int ways(int const n)
{
	if(n & 0x1)
		return 0;
	else
		return 1 << n / 2; // n <= 60
}

int main()
{
	int n;
	cin >> n;
	// find num ways to fill all 3xn tiles with the shape 
	// described in the picture below
	// 1 1
	// 0 1
	int w = ways(n);
	cout << w << endl;
}
