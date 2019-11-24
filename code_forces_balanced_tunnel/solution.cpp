#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> enter(n);
    for(auto & car : enter)
        cin >> car;
    vector<int> exit(n);
    for(auto & car : exit)
        cin >> car;
    int i{ 0 };
    int j{ 0 };
    unordered_set<int> fines;
    while(j < n)
    {
        if(fines.count(enter[i]))
        {
            ++i;
        }
        else if(enter[i] == exit[j])
        {
            ++i;
            ++j;
        }
        else
        {
            fines.insert(exit[j]);
            ++j;
        }
    }
    cout << fines.size() << endl;
}
