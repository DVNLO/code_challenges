#include <bits/stdc++.h>
using namespace std;

int
move_all_black(vector<int> const & p)
{
    int ret{ 0 };
    for(size_t i{ 0U }; i < p.size(); ++i)
    {
        ret += abs((2 * static_cast<int>(i)) - p[i]);
    }
    return ret;
}

int
move_all_white(vector<int> const & p)
{
    int ret{ 0 };
    for(size_t i{ 0U }; i < p.size(); ++i)
    {
        ret += abs((2 * static_cast<int>(i) + 1) - p[i]);
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    size_t SIZE{ static_cast<size_t>(n / 2) };
    vector<int> p(SIZE);
    for(size_t i{ 0 }; i < SIZE; ++i)
    {
        cin >> p[i];
        --p[i];
    }
    sort(p.begin(), p.end());
    int MAB{ move_all_black(p) };
    int MAW{ move_all_white(p) };
    int ret{ min(MAB, MAW) };
    cout << ret << endl;
}
