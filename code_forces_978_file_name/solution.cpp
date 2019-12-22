#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int min_del_count{ 0 };
    int x_count;
    for(int i{ 0 }; i < n;)
    {
        x_count = 0;
        while(i < n &&
                s[i] != 'x')
            ++i;
        while(i < n 
                && s[i] == 'x')
        {
            ++x_count;
            ++i;
        }
        if(x_count)
        {
            x_count -= 2;
            if(x_count > 0)
                min_del_count += x_count;
        }
        else
            ++i;
    }
    cout << min_del_count << endl;
}
