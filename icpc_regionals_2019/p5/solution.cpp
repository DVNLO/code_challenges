#include <bits/stdc++.h>
using namespace std;

bool is_swap_free(string const & left, 
                    string const & right)
{
    if(left.size() != right.size())
        return false;
    size_t diff_count = 0;
    size_t const size = left.size();
    for(size_t i = 0; i < size; ++i)
    {
        if(left[i] != right[i])
            ++diff_count;
    }
    return diff_count != 2;
}

void build_swap_free_sets(vector<set<string>> & swap_free_sets,
                            set<string> & current,
                            queue<string> & source)
{
    if(source_set.empty())
        swap_free_sets.push_back(current);
    while(!source.empty())
    {
        string s = source.front();
        source.pop();
        if(!current.count(s) && is_swap_free())
        {
            

    }
}

int main()
{
    int n;
    scanf("%d", &n);
    queue<string> qs
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        qs.emplace(s);
    }
    vector<set<string>> swap_free_sets;
    set<string> current;
    build_swap_free_sets(swap_free_sets, current, qs);

    return 0;
}
