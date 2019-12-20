#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>::size_type const STRIP_COUNT{ 4 };
    vector<int> A(STRIP_COUNT);
    for(vector<int>::size_type i{ 0 }; i < STRIP_COUNT; ++i)
        cin >> A[i];
    string s;
    cin >> s;
    long long cal_count{ 0 };
    for(auto const c : s)
    {
        cal_count += A[static_cast<vector<int>::size_type>(c - '1')];
    }
    cout << cal_count << endl;
}
