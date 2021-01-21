#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n < 0)
    {
        n *= -1;
        n = std::min((n/100)*10 + n % 10, n/10);
        n *= -1;
    }
    cout << n << endl;
}
