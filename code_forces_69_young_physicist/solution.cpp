#include <bits/stdc++.h>
using namespace std;
int main()
{
    size_t constexpr rank{ 3 };
    int sum_forces[rank] = { 0 };
    int forces[rank];
    int vector_count;
    cin >> vector_count;
    // compute sum of forces on the input vectors
    for(int i{ 0 }; i < vector_count; ++i)
    {
        for(int j{ 0 }; j < rank; ++j)
        {
            cin >> forces[j];
            sum_forces[j] += forces[j];
        }
    }
    // determine if sum of forces are in equilibrium
    // equilibrium occurs when sum_forces == [0, 0, 0]
    bool is_equilibrium{ true };
    for(int j{ 0 }; j < rank; ++j)
    {
        if(sum_forces[j] != 0)
        {
            is_equilibrium = false;
            break;
        }
    }
    if(is_equilibrium)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl; 
}
