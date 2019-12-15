#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unsigned chris_win_count{ 0 };
    unsigned mishka_win_count{ 0 };
    int chris_roll_val;
    int mishka_roll_val;
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> mishka_roll_val >> chris_roll_val;
        if(mishka_roll_val > chris_roll_val)
            ++mishka_win_count;
        else if(chris_roll_val > mishka_roll_val)
            ++chris_win_count;
        else    // tie
            continue;
    }
    if(mishka_win_count > chris_win_count)
        cout << "Mishka";
    else if(chris_win_count > mishka_win_count)
        cout << "Chris";
    else
        cout << "Friendship is magic!^^";
}
