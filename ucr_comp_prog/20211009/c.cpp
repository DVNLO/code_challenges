#include <bits/stdc++.h>
using namespace std;

// this does not converge since the numbers
// kick around between 1 and m in an infinite
// recursion. So the existing recursions must 
// be killed somehow. which is why bfs needs to 
// be explored rather than dfs. 
int 
find(int const n, int const m, int const c)
{
    // red : n = 2 * n
    // blue : n = n - 1
    cout << n << ' ' << m << ' ' << c << endl;
    if(n < 1 || n > m)
    {
        return INT_MAX;
    }
    if(n == m)
    {
        return c;
    }
    int const red = find(2 * n, m, c + 1);
    int const blue = find(n - 1, m, c + 1);
    return red < blue ? red : blue;
}

// so how do you program bfs for this problem?
// 0 : n
// 1 : n - 1, 2n
// 2 : (n - 1) - 1, 2(n - 1), (2n) - 1, 2(2n)
// 3 

int
bfs(queue<int> & vals, int const m)
{
    // you have an implicit graph
    // every node has a value v
    // and has known neighbors n - 1 and 2n
    // the queue comes in with some number of values
    // see if the value is m we are searching for
    // for each value compute the child
}

int main()
{
    // in:
    int n;
    int m;
    // out:
    // the minimum number of times one needs to push the
    // button required to get the number m out of the
    // the number n
    // n -> m;
    cin >> n >> m;
    int const press_count { find(n, m, 0) };
    cout << press_count << endl;
}
