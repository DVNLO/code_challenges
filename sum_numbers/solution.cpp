#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for(auto & c : s)
        if(isalpha(c))
            c = ' ';
    vector<int> vals;
    stringstream ss{ s };
    string tmp;
    while(ss >> tmp)
        vals.push_back(atoi(tmp.c_str()));
    long long acc{ 0 };
    for(auto const & val : vals)
        acc += val;
    cout << acc;
}
