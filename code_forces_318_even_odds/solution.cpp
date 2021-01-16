#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n;
    unsigned long long k;
    cin >> n >> k;
    --k;    // 1 based indexing, correction
    unsigned long long val;
    if(k < (n - n/2))
    {
        val = 2 * k + 1;
    }
    else
    {
        val = 2 * (k - (n - n/2)) + 2;
    }
    cout << val << endl;
    return 0;
}

