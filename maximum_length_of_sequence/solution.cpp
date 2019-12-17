#include <bits/stdc++.h>
using namespace std;

void initial_solution_Onlgn(vector<int> v, int n)
{
    sort(v.begin(), v.end());
    int max_run_len{ 0 };
    for(int i{ 1 }; i < n;)
    {
        int run_len{ 0 };
        while(i < n 
                && v[i - 1] == v[i] - 1)
        {
            ++run_len;
            ++i;
        }
        if(run_len)
            max_run_len = max(max_run_len, ++run_len);
        else
            ++i;
    }
    cout << max_run_len << endl;
}

void next_solution_On(vector<int> v)
{
    priority_queue<int, vector<int>, greater<int>> p(v.begin(), 
                                                        v.end(), 
                                                        greater<int>());
    int max_run_len{ 1 };
    int run_len;
    int cur_val;
    int prev_val{ p.top() };
    p.pop();
    while(!p.empty())
    {
        run_len = 1;
        cur_val = p.top();
        p.pop();
        while(!p.empty()
                && prev_val + 1 == cur_val)
        {
            ++run_len;
            prev_val = cur_val;
            cur_val = p.top();
            p.pop();
        }
        if(run_len)
            max_run_len = max(max_run_len, run_len);
        prev_val = cur_val;        
    }
    cout << max_run_len << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i{ 0 }; i < n; ++i)
        cin >> v[i];
    next_solution_On(v);
}
