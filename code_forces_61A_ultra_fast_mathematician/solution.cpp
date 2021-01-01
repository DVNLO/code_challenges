#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::string l;
    std::string r;
    cin >> l >> r;
    std::string out;
    size_t const SIZE{ l.size() };
    for(size_t i{ 0 }; i < SIZE; ++i)
    {
        if((l[i] == '0' && r[i] == '0')
            || (l[i] == '1' && r[i] == '1'))
        {
            out.push_back('0');
        }
        else if((l[i] == '0' && r[i] == '1') 
                || (l[i] == '1' && r[i] == '0'))
        {
            out.push_back('1');
        }
        else
        {
            return 1;
        }
    }
    cout << out << std::endl;
    return 0;
}

