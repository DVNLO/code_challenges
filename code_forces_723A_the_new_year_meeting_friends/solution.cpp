#include <bits/stdc++.h>
using namespace std;
int main()
{
    int X[3];
    cin >> X[0] >> X[1] >> X[2];
    sort(begin(X), end(X));
    cout << (X[1] - X[0]) + (X[2] - X[1]) << endl;
}
