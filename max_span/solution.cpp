#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i{ 0 }; i < n; ++i)
        cin >> vals[i];
    int max_span{ 1 };
    unordered_map<int, int> first_occurrences;
    for(int i{ 0 }; i < n; ++i)
    {
        if(!first_occurrences.count(vals[i]))
            first_occurrences.insert({ vals[i], i });
        max_span = std::max(max_span, i - first_occurrences[vals[i]] + 1);
        cout << i << ' ' << max_span << endl;
    }
    cout << max_span;
}
