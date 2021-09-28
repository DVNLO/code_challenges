#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned const WINDOW_ROWS{ 2U };
    unsigned const WINDOW_COLS{ 2U };
    char window[WINDOW_ROWS][WINDOW_COLS];
    for(int i{ 0U }; i < WINDOW_ROWS; ++i)
    {
        for(int j{ 0U }; j < WINDOW_COLS; ++j)
        {
            cin >> window[i][j];
        }
    }
    unsigned const BOARD_ROWS{ 5U };
    unsigned const BOARD_COLS{ 6U };
    char board[BOARD_ROWS][BOARD_COLS];
    for(unsigned i{ 0U }; i < BOARD_ROWS; ++i)
    {
        for(unsigned j{ 0U }; j < BOARD_COLS; ++j)
        {
            cin >> board[i][j];
        }
    }
    for(unsigned i{ 0U }; i <= (BOARD_ROWS - WINDOW_ROWS); ++i)
    {
        for(unsigned j{ 0U }; j <= (BOARD_COLS - WINDOW_COLS); ++j)
        {
            bool is_match{ true };
            for(unsigned k{ 0U }; k < WINDOW_ROWS; ++k)
            {
                for(unsigned l{ 0U }; l < WINDOW_COLS; ++l)
                {
                    if(board[i + k][j + l] != window[k][l])
                    {
                        is_match = false;
                        break;
                    }
                }
            }
            if(is_match)
            {
                cout << i << ' ' << j << '\n';
            }
        }
    }
    return EXIT_SUCCESS;
}

