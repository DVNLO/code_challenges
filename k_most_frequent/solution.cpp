#include <bits/stdc++.h>
using namespace std;

struct my_pair
{
    int key;
    int count;
};

bool operator<(my_pair const & lhs, my_pair const & rhs)
{
    return lhs.count < rhs.count;
}

vector<int> k_most_frequent(vector<int> const & v, 
                            int const k)
{
    vector<int> most_frequent_keys(k);
    unordered_map<int, int> key_to_counts;
    for(auto const & val : v)
    {
        if(key_to_counts.count(val))
            ++key_to_counts[val];
        else
            key_to_counts[val] = 1;
    }
    int const PAIR_COUNT = key_to_counts.size();
    vector<my_pair> pairs(PAIR_COUNT);
    int i{ 0 };
    for(auto const & key_count : key_to_counts)
    {
        my_pair p;
        p.key = key_count.first;
        p.count = key_count.second;
        pairs[i] = p;
        ++i;
    }
    priority_queue<my_pair> max_counts{ pairs.begin(), pairs.end() };
    for(int i{ 0 }; i < k; ++i)
    {
        most_frequent_keys[i] = max_counts.top().key;
        max_counts.pop();
    }
    return most_frequent_keys;
}

int main()
{
    vector<int> keys { 10 , 1, 2, 3, 7, 7, 7, 7, 4, 3, 2, 1, 0, 10, 10 };
    vector<int> ret{ k_most_frequent(keys, 2) };
    for(auto const val : ret)
        cout << val << ' ';
    cout << endl;
}
