// The following is my solution to a video I found when preparing
// for technical interviews. The prompt is to:
// Find a pair in a set of numbers such that the pair is equal to 
// a provided sum.

#include <bits/stdc++.h>
using namespace std;

// this solution assumes that the values are in ascending order
bool find_pair_sum_ascending(vector<int> const & vals,
				int const SIZE,
				int const TARGET,
				pair<int, int> & operands)
{
	bool rc{ false };
	vector<int>::const_iterator left{ vals.begin() };
	vector<int>::const_iterator right{ --vals.end() };
	int cur_sum;
	while(left < right)
	{
		cur_sum = *left + *right; 
		if(cur_sum == TARGET)
		{
			operands.first = *left;
			operands.second = *right;
			rc = true;
			break;
		}
		else if(cur_sum < TARGET)
			++left;
		else	//cur_sum > target;
			--right;
	}
	return rc;
}

// this solution does not assume that the vals are in ascending order.
bool find_pair_sum(vector<int> const & vals, 
			int const SIZE, 
			int const TARGET,
			pair<int, int> & operands)
{
	bool rc{ false };
	unordered_set<int> differences;
	int difference;
	for(int i{ 0 }; i < SIZE; ++i)
	{
		difference = TARGET - vals[i];
		if(differences.count(vals[i]))
		{
			operands.first = vals[i];
			operands.second = difference;
			rc = true;
			break;
		}
		differences.insert(difference);
	}
	return rc;
}

void print_result(bool const rc, pair<int, int> const & operands)
{
	if(rc)
		cout << operands.first << ' ' << operands.second << endl;
	else
		cout << "false\n";
}

int main()
{
	int SIZE;
	cin >> SIZE;
	vector<int> vals(SIZE);
	for(int i{ 0 }; i < SIZE; ++i)
		cin >> vals[i];
	int TARGET;
	cin >> TARGET;
	pair<int, int> operands;
	bool rc{ find_pair_sum(vals, SIZE, TARGET, operands) };
	print_result(rc, operands);
	rc = find_pair_sum_ascending(vals, SIZE, TARGET, operands);
	print_result(rc, operands);
	
}
