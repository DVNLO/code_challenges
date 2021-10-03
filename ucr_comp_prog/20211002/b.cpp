#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 3 is the special doll
    int dolls[] = { 1, 2, 3, 4, 5 };
    long n; // swaps
    cin >> n;
    for(long i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        swap(dolls[a - 1], dolls[b - 1]);
    }
    for(long i = 0; i < 5; ++i)
    {
        if(dolls[i] == 3)
        {
            cout << i + 1 << endl;
            break;
        }
    }   
}
