#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    getline(cin, a);
    size_t len_a = a.size();
    string b;
    getline(cin, b);
    size_t len_b = b.size();
    size_t i = 0;
    while(a[i] == '0' && i < len_a)
    {
        ++i;
    }
    size_t j = 0;
    while(b[j] == '0' && j < len_b)
    {
        ++j;
    }
    if(len_a - i > len_b - j)
    {
        puts(">");
        return EXIT_SUCCESS;
    }
    else if(len_a - i < len_b - j)
    {
        puts("<");
        return EXIT_SUCCESS;
    }
    else
    {
        while(i < len_a && j < len_b)
        {
            if(a[i] > b[j])
            {
                puts(">");
                return EXIT_SUCCESS;
            }
            else if(a[i] < b[j])
            {
                puts("<");
                return EXIT_SUCCESS;
            }
            ++i;
            ++j;
        }
        puts("=");
        return EXIT_SUCCESS;
    }
}
