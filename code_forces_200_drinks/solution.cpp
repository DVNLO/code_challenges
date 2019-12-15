#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long acc{ 0 };
    int tmp;
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> tmp;
        acc += tmp;
    }
    cout << static_cast<double>(acc) / n << endl;
}

