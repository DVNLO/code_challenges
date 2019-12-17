#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>::iterator left, 
                vector<int>::iterator right)
{
    if(left >= right)
        return;
    --right;    // assuming [left...right) range bounds
    while(left < right)
    {
        swap(*left, *right);
        ++left;
        --right;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i{ 0 }; i < n; ++i)
        cin >> v[i];
    reverse(v.begin(), v.end());
    for(auto const val : v)
        cout << val << ' ';
    cout << endl;
}


