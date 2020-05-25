#include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> const & lhs,
		vector<int> const & rhs)
// returns a vector<int> ret containing the element wise
// sum of lhs and rhs. The i-th element of lhs and rhs
// is assumed to be the coefficient of the 10^i-th term.
// For example an input { 8, 5, 4 } is the base 10 number
// 458 = 4 * 10^2 + 5 * 10^1 + 8 * 10^0. 
{
	size_t const LHS_SIZE{ lhs.size() };
	size_t const RHS_SIZE{ rhs.size() };
	size_t const MAX_SIZE{ std::max(LHS_SIZE, RHS_SIZE) };
	size_t const MIN_SIZE{ std::min(LHS_SIZE, RHS_SIZE) };
	vector<int> ret(MAX_SIZE + 1, 0);
	int tmp;
	size_t i{ 0U };
	for(; i < MIN_SIZE; ++i)
	{
		tmp = ret[i] + lhs[i] + rhs[i];
		if(tmp > 9)
		{
			++ret[i + 1];
			tmp -= 10;
		}
		ret[i] = tmp;
	}
	for(; i < LHS_SIZE; ++i)
		ret[i] += lhs[i];
	for(; i < RHS_SIZE; ++i)
		ret[i] += rhs[i];
	return ret;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i{ 0 }; i < n; ++i)
		cin >> a[i];
	vector<int> b(n);
	for(int i{ 0 }; i < n; ++i)
		cin >> b[i];
	vector<int> c = add(a, b);
	for(int i{ 0 }; i < n; ++i)
		cout << c[i] << ' ';
	cout << endl;
}
