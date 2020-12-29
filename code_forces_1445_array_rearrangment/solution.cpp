#include <bits/stdc++.h>
using namespace std;

bool handle_test_case()
{
	int n; 
	int x;
	cin >> n >> x;
	vector<int> A(n);
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> A[i];
	}
	vector<int> B(n);
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> B[i];
	}
	bool ret{ true };
	for(int i{ 0 }; i < n; ++i)
	{
		ret = A[i] + B[n - i - 1] <= x;
		if(!ret)
		{
			break;
		}
	}
	return ret;

}


int main()
{
	int t;	// test case count
	cin >> t;
	for(int j{ 0 }; j < t; ++j)
	{
		bool res = handle_test_case();
		if(res)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}
