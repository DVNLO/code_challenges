#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M{ 20 };
    int N{ 20 };
    int const MIN_ROW_IDX{ 0 };
    int const MIN_COL_IDX{ 0 };
    int const MAX_ROW_IDX{ M - 1 };
    int const MAX_COL_IDX{ N - 1 };
    pair<int, int> cur_pos{ MAX_ROW_IDX , 0 };
    pair<int, int> final_pos{ MAX_ROW_IDX, MAX_COL_IDX };
    queue<pair<int, int>> points;
    points.push(cur_pos);
    int ways_to_final_pos{ 0 };
    while(!points.empty())
    {
        cur_pos = points.front();
        points.pop();
        if(cur_pos == final_pos)
        {
            ++ways_to_final_pos;
            continue;
        }
        int next_col = cur_pos.second + 1;
        if(next_col > MAX_COL_IDX)
            continue;
        else
            points.push({ cur_pos.first, next_col });   // go right
        int up_row = cur_pos.first - 1;
        if(up_row >= MIN_ROW_IDX)
            points.push({ up_row, next_col });  // go up, right
        int dwn_row = cur_pos.first + 1;
        if(dwn_row <= MAX_ROW_IDX)  // go down, right
            points.push({ dwn_row, next_col });
    }
    cout << ways_to_final_pos << endl;
}
