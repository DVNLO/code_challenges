#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;  // plank count
    int k;  // consecutive plank count
    cin >> n >> k;
    vector<long long> planks(n);
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> planks[i];
        //cout << planks[i] << ' ';
    }
    //cout << '\n';

    // count the k-consecutive planks
    // accumulate in ksum vector
    vector<long long> ksum(n, 0);
    ksum[0] = planks[0]; 
    cout << ksum[0] << ' ';
    for(int i{ 1 }; i < n; ++i)
    {
        ksum[i] = ksum[i - 1] + planks[i];
        cout << ksum[i] << ' ';
    }
    cout << '\n';
    for(int i{ 0 }; i < n; ++i)
    {
        if(i >= k)
            ksum[i] -= ksum[i - k];
        cout << ksum[i] << ' ';
    }
    cout << '\n';

    // find minimum ksum index
    long long min_sum_val{ ksum[k - 1] };
    int min_sum_idx{ k - 1 };
    for(int i{ k }; i < n; ++i)
    {
        //cout << ksum[i] << ' '; 
        if(ksum[i] < min_sum_val)
        {
            min_sum_val = ksum[i];
            min_sum_idx = i;
        }
    }
    //cout << '\n';
    // add 1 to align with problem statement index scheme
    cout << min_sum_idx - (k - 1) + 1 << endl;
}

