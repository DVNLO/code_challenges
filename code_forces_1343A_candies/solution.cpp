#include <bits/stdc++.h>
using namespace std;

// the following solution is not accepted due to a 
// timeout. The overall algorithm here is correct, but
// inefficient. The runtime of my implementation is
// O(log(k)*x*log(k)). There is a trick however, where
// we can discover if a positive integer exists by 
// searching more directly for the existence of a positive
// multiple. Much more clever. The solution in the bloc
// entry is available here : http://codeforces.com/blog/entry/76352
// Essentially it relies on an observation of geometric sums. 
// There is also some helpful examples of using provided
// facts about the input space to limit the scope of our
// search space. Overall a great problem. I may
// return to this in the future to implement the more
// efficient solution.

// the problem spec : http://codeforces.com/problemset/problem/1343/A

long long
radix_sum(long long const base, long long const x, long long const k)
{
    long long coef{ 1 };
    long sum{ 0 };
    for(long long i{ 0 }; i < k; ++i)
    {
        sum +=  coef * x;
        coef *= 2;
    }
    return sum;
}

long long 
find_x(long long const n)
{
    for(long long k{ 2 }; k <= (log2(n) + 1); ++k)
    {
        long long x{ 1 };
        long long sum;
        do
        {
            sum = radix_sum(2, x, k);
//            cout << sum << " =?= " << n << endl;
            if(sum == n)
                return x;
            ++x;
        }
        while(sum < n);
    }
    return -1;
}

int main()
{
    int t;  // num test cases
    cin >> t;
    vector<int> N(t);   // num candies found per test case
    for(int i{ 0 }; i < t; ++i) // grab input
    {
        cin >> N[i];
//        cout << N[i] << endl;
    }
    for(int i{ 0 }; i < t; ++i) // compute
    {
        N[i] = find_x(N[i]);
    }
    for(int i{ 0 }; i < t; ++i) // provide output
    {
        cout << N[i] << '\n';
    }
    cout << endl;
}
