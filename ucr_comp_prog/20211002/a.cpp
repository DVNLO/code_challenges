#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n,m;
    cin >> n >> m;
    long toad_count = 0;
    string s;
    for(long i = 0; i < n; ++i)
    {
        cin >> s;
        for(long j = 0; j < m; ++j)
        {
            if(s[j] == 't')
                ++toad_count;
        }
        s.clear();
    }
    cout << toad_count << endl;
}
