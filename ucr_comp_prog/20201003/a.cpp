#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    long long r{ n % m };  // remainder
    long long out;
    long long cost_build{ (m  - r) * a };
    long long cost_destroy{ r * b };
    out = min(cost_build, cost_destroy);
    cout << out << endl;
}

// the important observation in this problem
// is recognizing that the remainder is always bounded
// between 0 and m, exclusive. Therefore, to get the 
// cost to build we need to know that difference m - r 
// where r is the remainder.

int incorrect_main()
{
    // n commentary boxes
    // m reginal delegations come to cup
    // every delegation gets the same number of commentary boxes
    // each box is occupied by exactly one delegation
    // if n is not divisible by m it is impossible to distrubute the boxes to the delegations at moment
    // what is the minimumum amount of burles organizers should pay to satisfy all the delegations
    // to make the number of boxes divisible by m
    // in :
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    // out : minimum number of burles organizers pay to satisfy delegations
    int r{ n % m };  // remainder
    int out{ 0 };
    if(r)
    {
        int q{ n / m };
        int cost_build{ ((m * (q + 1)) - (n)) * a };
        int cost_destroy{ r * b };
        out = min(cost_build, cost_destroy);
    }
    cout << out << endl;
}

// not accepted on test case 4, idk why.
