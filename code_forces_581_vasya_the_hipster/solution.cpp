#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, b;
    cin >> r >> b;
    int m{ min(r, b) };
    r -= m;
    b -= m;
    int p{ 0 };
    if(r)
    {
        p = r / 2;
    }
    else if(b)
    {
        p = b / 2;
    }
    cout << m << ' ' << p << endl;
}
