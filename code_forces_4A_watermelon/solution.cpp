#include <bits/stdc++.h>
using namespace std;


int main()
{
    int w;
    cin >> w;
    // 1, 2, 3, 4, 5, 6, 7, 8, ...
    // 0, 0, 0, 1, 0, 1, 0, 1, ...
    // by looking at examples we can conclude the following condition
    if(w > 3 && w % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

/* 
// My initial implementation does way to much work.
// We can detect if the weight can be split into two 
// even values such that w = a + b. When the division
// is made a and b must be even therefore there must 
// exist i and j such that a = 2i and b = 2j. But, we
// do not need to find i and j only detect if w can 
// be seperated into such quantities. So, if a or b
// is not even then either a or b introduces a + 1 term
// such that w = 2i + 2j + 1, so essentially it is enough
// to detect if w is divisible by 2. If it is then the + 1
// term doesn't exist and we can say i and j exist. 
int main()
{
    int w;
    cin >> w;
    bool response{ false };
    // search for a pair (i,j) such that 
    // w = 2i + 2j. If pair (i, j) satisfy 
    // this invariant then there exists two 
    // pieces of even weight the watermelon
    // can be divided into.
    for(int i{ 0 }; i < w; ++i)
    {
        for(int j{ i }; (w - (2 * i)) <= (2 * j); ++j)
        {
            if(w == (2 * i) + (2 * j))
            {
                response = true;
                break;
            }
        }
    }
    if(response)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
*/
