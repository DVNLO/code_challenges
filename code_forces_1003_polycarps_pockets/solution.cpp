#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[100] = { 0 };
    int val;
    int max_count{ 0 };
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> val;
        max_count = max(max_count, ++A[val - 1]);
    }
    cout << max_count;
}
