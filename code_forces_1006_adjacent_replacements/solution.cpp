#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int tmp;
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> tmp;
        if(!(tmp & 0x1))
            --tmp;
        v[i] = tmp;
    }
    for(auto const val : v)
        cout << val << ' ';
    cout << endl;
}
