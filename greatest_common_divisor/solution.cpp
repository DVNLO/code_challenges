#include <bits/stdc++.h>
using namespace std;

unsigned
gcd_recursive(unsigned const a, 
              unsigned const b)
// assumes a >= b >= 0
{
    if(!b)
    {
        return a;
    }
    else
    {
        return gcd_recursive(b, a % b);
    }
}

unsigned
gcd_iterative(unsigned a,
              unsigned b)
// assumes a >= b >= 0
{
    if(!b)
    {
        return a;
    }
    unsigned c{ a % b};
    while(c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    unsigned const UINT_MAX_LOCAL{ numeric_limits<unsigned>::max() };
    for(unsigned i{ 0U }; i < UINT_MAX_LOCAL; ++i)
    {
        for(unsigned j{ i }; j < UINT_MAX_LOCAL; ++j)
        {
            unsigned lib_result{ gcd(j, i) };
            unsigned my_result_recur{ gcd_recursive(j, i) };
            unsigned my_result_iter{ gcd_iterative(j, i) };
            if(lib_result != my_result_recur
               || lib_result != my_result_iter
               || my_result_recur != my_result_iter)
            {
                cout << lib_result << ' '
                     << my_result_recur << ' '
                     << my_result_iter << '\n';
            }
        }
    }
    cout << "done." << endl;    // there's no way this will complete in a reasonable amount of time. 
}
