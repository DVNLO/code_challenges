#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long n, t;
    cin >> n >> t;
    vector<string> board(n);
    vector<vector<unsigned long>> costs(n + 2, vector<unsigned long>(n + 2, ULONG_MAX));
    for(unsigned long i{ 0U }; i < n; ++i)
    {
        cin >> board[i];
    }
    for(unsigned long i{ 1U }; i <= n; ++i)
    {
        for(unsigned long j{ 1U }; j <= n; ++j)
        {
            costs[i][j] = min(costs[i][j], costs[i][j - 1]);
            costs[i][j] = min(costs[i][j], costs[i][j + 1]);
            costs[i][j] = min(costs[i][j], costs[i - 1][j]);
            costs[i][j] = min(costs[i][j], costs[i + 1][j]);
            costs[i][j] += 1 + (board[i - 1][j - 1] == 'b' ? t : 0);
        }
    }
    cout << costs[n][n] << endl;
}
