#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<char> v(n);
    for(int i{ 0 }; i < n; ++i)
        cin >> v[i];
    vector<char>::iterator itr{ v.begin() };
    vector<char>::const_iterator const END{ v.end() };
    vector<int> encryption;
    while(itr < END)
    {
        int encrypt_count{ 0 };
        while(itr < END 
                && *itr == 'B')
        {
            ++encrypt_count;
            ++itr;
        }
        if(encrypt_count)
            encryption.emplace_back(encrypt_count);
        else
            ++itr;
    }
    cout << encryption.size() << '\n';
    for(auto const val : encryption)
        cout << val << ' ';
    cout << endl;
}
