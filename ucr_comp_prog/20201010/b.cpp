#include <bits/stdc++.h>
using namespace std;
int main()
{
    size_t n;
    size_t m;
    cin >> n >> m;
    vector<string> a(n, string(m, ' '));
    vector<int> degs(m, 0U);
    for(size_t i{ 0U }; i < n; ++i)
    {    
        for(size_t j{ 0U }; j < m; ++j)
        {
            cin >> a[i][j];
            if(a[i][j] == '1')
            {
                ++degs[j];
            }
        }
    }
    bool can_remove;
    for(size_t i{ 0U }; i < n; ++i)
    {
        can_remove = true;
        for(size_t j{ 0U }; j < m; ++j)
        {
            if(a[i][j] == '1' && degs[j] - 1 <= 0)
            {
                can_remove = false;
                break;
            }
        }
        if(can_remove)
        {
            break;
        }
    }
    if(can_remove)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
}
