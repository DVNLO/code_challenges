/* Dynamic programming (DP) is the process of  solving sub-problems
 * and building the aswer from the sub-problems. DP is particullarly
 * useful when problems exhibit a recursive structure. Intermediate
 * values can be stored (memoized) while progressing to the desired
 * solution.
 */

#include <bits/stdc++.h>
using namespace std;

void print(int const * const arr, int const size)
{
	for(int i{ 0 }; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
}

int change_combinations(int const coins[], 
			int const coin_count, 
			int const amt)
{
	int const AMT_TERMINAL_IDX{ amt + 1 };
	int * combinations = new int[AMT_TERMINAL_IDX]{ 0 };
	if(!combinations)
		return -1;
	combinations[0] = 1;
	for(int i{ 0 }; i < coin_count; ++i)
	{
		for(int j{ coins[i] }; j < AMT_TERMINAL_IDX; ++j)
		{
			combinations[j] += combinations[j - coins[i]];
		}
		print(combinations, AMT_TERMINAL_IDX);
		cout << '\n';
	}
	return combinations[amt];
}

int main()
{
	int const COIN_COUNT{ 3 };
	int coins[COIN_COUNT] = { 1, 2, 5 };
	int amt{ 12 };
	int ways_to_make_change { change_combinations(coins, 
							COIN_COUNT, 
							amt) };
	cout << ways_to_make_change << endl;
}

