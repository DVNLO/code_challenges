#include <bits/stdc++.h>
using namespace std;

int main()
{
    string base;
    cin >> base;
    string remove;
    cin >> remove;
    auto write{ base.begin() };
    auto lead{ base.begin() };
    auto follow{ base.begin() };
    auto remove_itr{ remove.begin() };
    while(lead < base.end())
    {
        follow = lead;
        remove_itr = remove.begin();
        while(lead < base.end()
                && remove_itr < remove.end()
                && *lead == *remove_itr)    // advance over possible match
        {
            ++lead;
            ++remove_itr;
        }
        if(remove_itr != remove.end())  // no match
        {
            do
            {
                *write = *follow;
                ++write;
                ++follow;
            }
            while(follow < lead);   // copy from follow to lead
            ++lead;
        }
    }
    base.erase(write, base.end());
    cout << base << endl;
}
