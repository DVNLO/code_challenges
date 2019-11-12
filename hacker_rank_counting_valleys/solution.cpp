//www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup&h_r=next-challenge&h_v=zen = size - i - 1;
#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int valley_count = 0;
    int cur_elevation = 0;
    int prev_elevation = 0;
    for(char const c : s)
    {
        if(c == 'U')
            ++cur_elevation;
        else if(c == 'D')
            --cur_elevation;
        else
            return -1;
        if(prev_elevation < 0 && cur_elevation == 0)
            ++valley_count;
        prev_elevation = cur_elevation;
    }
    return valley_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

