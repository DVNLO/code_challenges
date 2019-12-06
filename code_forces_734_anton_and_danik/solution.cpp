#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    uint64_t a_count{ 0 };
    uint64_t d_count{ 0 };
    for(auto const c : s)
    {
        if(c == 'A')
            ++a_count;
        else if(c == 'D')
            ++d_count;
        else
            exit(EXIT_FAILURE);
    }
    if(a_count > d_count)
        puts("Anton");
    else if(d_count > a_count)
        puts("Danik");
    else
        puts("Friendship");
    return 0;
}
        
