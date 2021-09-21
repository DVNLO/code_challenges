#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;  // table size
    cin >> n;
    int x;  // find
    cin >> x;
    int count{ 0 };
    /* Initial O(n^2) solution, but it times out...
    for(int i{ 1 }; i <= n; ++i)
    {
        int k{ i * i };
        if(k == x)
        {
            ++count;
        }
        for(int j{ i + 1 }; j <= n; ++j)
        {
            k += i;
            if(k == x)
            {
                count += 2;
            }
        }
    }
    */
    // after looking at the tutorial I learned that x can only appear in each
    // a maximum of one time so we can reduce runtime to O(n) by checking
    // divisibility.
    for(int i{ 1 }; i <= n; ++i)
    {
        if(x % i == 0 && x / i <= n)
        {
            ++count;
        }
    }
    cout << count;
}
