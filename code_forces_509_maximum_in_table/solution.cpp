#include <bits/stdc++.h>
using namespace std;
// The following computes the maximum value in a table 
// constructed from the invariants proposed in the 
// code foreces prompt. My implementation is O(n^2),
// but I believe the relationship maybe solvable 
// via a recurrence relation. The terminal value 
// along the main diagonal will always have the maximum
// value. The recurrence relation solution will be 
// O(1).
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 1));
    for(int i{ 1 }; i < n; ++i)
    {
        for(int j{ 1 }; j < n; ++j)
        {
            m[i][j] = m[i - 1][j] + m[i][j - 1];
        }
    }
    cout << m[n - 1][n - 1];
}
