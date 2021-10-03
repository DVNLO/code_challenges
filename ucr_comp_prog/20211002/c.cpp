#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n;     // num pieces in each castle
    long m;     // num rounds in game;
    cin >> n >> m;
    long s1 = n;
    long s2 = n;
    bool won = false;
    for(long r = 0; r < m; ++r)
    {
        int h1, h2, h3, h4;
        cin >> h1 >> h2 >> h3 >> h4;
        int p1 = h1 * h2;
        int p2 = h3 * h4;
        s1 -= p2;
        s2 -= p1;
        if(s1 <= 0 && s2 <= 0)
        {
            won = true;
            cout << "It's a tie at round " << r + 1 << "!";
            break;
        }
        else if(s1 <= 0 && s2 > 0)
        {
            won = true;
            cout << "Team 2 wins at round " << r + 1 << "!";
            break;
        }
        else if(s1 > 0 && s2 <= 0)
        {
            won = true;
            cout << "Team 1 wins at round " << r + 1 << "!";
            break;
        }
    }
    if(!won)
    {
        cout << "Oh no!";
    }
    cout << endl;
}
