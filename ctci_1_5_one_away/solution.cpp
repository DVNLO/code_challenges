/* This was a more challenging problem than I anticipated initially.
 * I believe the challenge was a result of trying to match the problem
 * into theory I knew from the longest common sub sequence algorithm. 
 * While the edit operations in this problem are somewhat similar to this
 * problem it isn't the same so I should not be jumping to matching
 * this implementation to this knowledge. Rather than trying to match,
 * attempt to interptet the problem for what it is. Try to clarify your
 * assumptions, and if they don't match the problem move onward to 
 * the next idea. Moving onward to the next idea was where I became 
 * confused on this problem.
 */

#include <bits/stdc++.h>
using namespace std;

bool is_one_insert_away(string const source, string const target)
// assumes soruce and target differ by 1 character length
{
    bool ret{ true };
    size_t const SIZE_SOURCE{ source.size() };
    size_t const SIZE_TARGET{ target.size() };
    bool is_inserted{ false };
    size_t i{ 0U };
    size_t j{ 0U };
    while(i < SIZE_SOURCE && j < SIZE_TARGET)
    {
        if(source[i] != target[j])
        {
            if(is_inserted)
            {
                ret = false;
                break;
            }
            else
            {
                is_inserted = true;
            }
            ++i;
        }
        else
        {
            ++i;
            ++j;
        }
    }
}

bool is_one_replace_away(string const l, string const r)
// assumes l and r are equal lengths
{
    bool ret{ true };
    bool is_replaced{ false };
    size_t const SIZE_L{ l.size() };
    for(size_t i{ 0U }; i < SIZE_L; ++i)
    {
        if(l[i] != r[i])
        {
            if(is_replaced)
            {
                ret = false;
                break;
            }
            is_replaced = true;
        }
    }
    return ret;
}

bool is_one_away(string const l, string const r)
{
    bool ret{ false };
    size_t const SIZE_L{ l.size() };
    size_t const SIZE_R{ r.size() };
    if(SIZE_L == SIZE_R)
    {
        ret = is_one_replace_away(l, r);
    }
    else if(SIZE_L > SIZE_R
            && SIZE_L - SIZE_R == 1)
    {
        ret = is_one_insert_away(l, r);
    }
    else if(SIZE_R > SIZE_L
            && SIZE_R - SIZE_L == 1)
    {
        ret = is_one_insert_away(r, l);
    }
    else
    {
        ret = false;
    }
    return ret;
}

int main()
{
    string l, r;
    cin >> l >> r;
    bool is_one_away_result{ is_one_away(l, r) };
    if(is_one_away_result)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
}

