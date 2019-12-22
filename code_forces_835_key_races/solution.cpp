#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int time_p1{ t1 + s * v1 + t1 };
    int time_p2{ t2 + s * v2 + t2 };
    if(time_p1 < time_p2)
        cout << "First";
    else if(time_p2 < time_p1)
        cout << "Second";
    else
        cout << "Friendship";
    cout << endl;
}
