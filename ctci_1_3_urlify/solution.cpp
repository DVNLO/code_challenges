#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(std::cin, s);
    if(s.empty())
    {
        return EXIT_SUCCESS;
    }
    unsigned long space_count{ 0U };
    for(char const c : s)
    {
        if(c == ' ')
        {
            ++space_count;
        }
    }
    size_t const SIZE_S_INITIAL{ s.size() };
    s.resize(SIZE_S_INITIAL + 2 * space_count);
    size_t const SIZE_S_FINAL{ s.size() };
    size_t j{ SIZE_S_FINAL - 1 };
    for(size_t i{ SIZE_S_INITIAL - 1 }; i < SIZE_S_INITIAL; --i)
    {
        if(s[i] == ' ')
        {
            s[j] = '0';
            --j;
            s[j] = '2';
            --j;
            s[j] = '%';
            --j;
        }
        else
        {
            s[j] = s[i];
            --j;
        }
    }
    cout << s << endl;
}


