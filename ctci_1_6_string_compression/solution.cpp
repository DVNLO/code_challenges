#include <bits/stdc++.h>
using namespace std;

string 
string_compress(string const val)
{
    if(val.empty())
    {
        return val;
    }
    size_t i{ 0U };
    size_t const SIZE_VAL{ val.size() };
    string compressed;
    char c = val[i];
    size_t count{ 1U };
    while(i < SIZE_VAL)
    {
        ++i;
        if(val[i] != c)
        {
            compressed.push_back(c);
            compressed += to_string(count);
            c = val[i];
            count = 1U;
        }
        else
        {
            ++count;
        }
    }
    if(val.size() < compressed.size())
    {
        return val;
    }
    else
    {
        return compressed;
    }
}

int main()
{
    string s;
    cin >> s;
    string compressed_s{ string_compress(s) };
    cout << compressed_s << endl;
}
