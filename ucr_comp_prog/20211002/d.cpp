#include <bits/stdc++.h>
using namespace std;


long
fill(vector<vector<char>> & board, int const i, int const j)
{
    if(i < 0 || j < 0 || i > board.size() || j > board[0].size() || board[i][j] != '.')
    {
        return 0;
    }
    else
    {
        board[i][j] = 'V';
        long ret = 1;
        if(board[i - 1][j] == '.')
        {
            ret += fill(board, i - 2, j);
        }
        if(board[i + 1][j] == '.')
        {
            ret += fill(board, i + 2, j);
        }
        if(board[i][j - 1] == '.')
        {
            ret += fill(board, i, j - 2);
        }
        if(board[i][j + 1] == '.')
        {
            ret += fill(board, i, j + 2);
        }
        return ret;
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    r = 2 * r + 1;
    c = 2 * c + 1;
    vector<vector<char>> board(r, vector<char>(c));
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> board[i][j];
        }
    }
    vector<long> result;
    for(int i = 1; i < r; i += 2)
    {
        for(int j = 1; j < c; j += 2)
        {
            if(board[i][j] != '.')
            {
                continue;
            }
            long sz = fill(board, i, j);
            result.push_back(sz);
        }
    }
    sort(result.begin(), result.end(), greater<long>());
    for(auto const val : result)
    {
        cout << val << ' ';
    }
    cout << endl;
}
