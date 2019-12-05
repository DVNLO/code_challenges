#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> P(n);
    for(int i = 0; i < n; ++i)
        cin >> P[i];
    vector<int> G(n);
    for(int i = 0; i < n; ++i)
        G[P[i] - 1] = i + 1;
    for(auto const val : G)
        cout << val << ' ';
    cout << endl;
    return 0;
}
        

