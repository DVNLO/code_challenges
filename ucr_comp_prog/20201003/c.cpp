#include <bits/stdc++.h>
using namespace std;

bool
is_regular(string const str)
{
    size_t open_count{ 0 };
    for(char c : str)
    {
        if(!open_count)
        {
            if(c == '(')
            {
                ++open_count;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(c == '(')
            {
                ++open_count;
            }
            else if(c == ')')
            {
                --open_count;
            }
            else
            {
                return false;
            }
        }
    }
    return open_count == 0;
}

int main()
{
    int n;
    cin >> n;
    vector<string> bracks(n);
    string s;
    for(size_t i{ 0U }; i < n; ++i)
    {
        cin >> s;
        bracks[i] = s;
    }
    int out{ 0 };
    for(size_t i{ 0U }; i < n; ++i)
    {
        for(size_t j{ 0U }; j < n; ++j)
        {
            if(is_regular(bracks[i] + bracks[j]))
            {
                ++out;
            }
        }
    }
    cout << out << endl;
}
