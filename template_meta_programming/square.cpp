#include <bits/stdc++.h>
using namespace std;

template<int val>
struct square
{
    static constexpr int value{ val * val };
};

int main()
{
    cout << square<130>::value << endl;
    return 0;
}
