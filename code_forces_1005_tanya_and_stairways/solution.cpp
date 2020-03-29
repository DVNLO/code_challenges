#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int lead;
    cin >> lead;
    int follow;
    int stairway_count{ 1 };
    for(int i{ 1 }; i < n; ++i)
    {
        follow = lead;
        cin >> lead;
        if(lead <= follow)
        {
            ++stairway_count;
            v.emplace_back(follow);
        }
    }
    v.emplace_back(lead);
    cout << stairway_count << '\n';
    for(auto const val : v)
        cout << val << ' ';
    cout << endl;
}
        
    
