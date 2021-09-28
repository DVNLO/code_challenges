// https://codeforces.com/group/lr4PWkKiEw/contest/344869/problem/C
// not really a fan of this problem. 
#include <bits/stdc++.h>
using namespace std;

size_t constexpr GRID_DIM{ 5U };

inline
bool
is_alive(size_t const row, size_t const col, 
         vector<uint16_t> const & tracks)
{
    // transform is a special matrix to map the enumerated tracks
    // to the matrix indicies.
    int const transform[10] = { 4, 3, 2, 1, 0, 0, 1, 2, 3, 4 };
    for(auto const track : tracks)
    {
        int idx = track - 1;
        if(transform[idx] == row || transform[idx] == col)
            return false;
    }
    return true;
}


void
kill(bool grid[GRID_DIM][GRID_DIM], size_t const rows_sz, 
     size_t const cols_sz, vector<uint16_t> const & tracks)
{
    for(size_t i{ 0U }; i < rows_sz; ++i)
    {
        for(size_t j{ 0U }; j < cols_sz; ++j)
        {
            grid[i][j] &= is_alive(i, j, tracks);
        }
    }
}


bool
gen(bool grid[GRID_DIM][GRID_DIM], size_t const rows_sz, 
    size_t const cols_sz)
{
    bool ret = false;
    for(size_t i{ 0U }; i < rows_sz; ++i)
    {
        for(size_t j{ 0U }; j < cols_sz; ++j)
        {
            if(grid[i][j])
            {
                ret = true;
                if(i - 1 < i)
                    grid[i - 1][j] = true;
                if(i + 1 < rows_sz)
                    grid[i + 1][j] = true;
                if(j - 1 < j)
                    grid[i][j - 1] = true;
                if(j + 1 < cols_sz)
                    grid[i][j + 1] = true;
            }
        }
    }
    return ret;
}


void
print(bool const grid[GRID_DIM][GRID_DIM], size_t const rows_sz, 
      size_t const cols_sz)
{
    for(size_t i{ 0U }; i < rows_sz; ++i)
    {
        for(size_t j{ 0U }; j < cols_sz; ++j)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}


int main()
{
    uint16_t n; // num charging chucks
    cin >> n;
    bool grid[GRID_DIM][GRID_DIM];
    for(size_t i{ 0U }; i < GRID_DIM; ++i)
    {
        for(size_t j{ 0U }; j < GRID_DIM; ++j)
        {
            grid[i][j] = true;
        }
    }
    vector<vector<uint16_t>> time_tracks(n);
    for(uint16_t i{ 0U }; i < n; ++i)
    {
        uint16_t t;
        uint16_t x;
        cin >> t >> x;
        time_tracks[t].push_back(x);
    }
    /*
    for(uint16_t i{ 0U }; i < time_tracks.size(); ++i)
    {
        cout << i << " : ";
        for(uint16_t j{ 0U }; j < time_tracks[i].size(); ++j)
        {
            cout << time_tracks[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    size_t end_time{ 0U };
    for(uint16_t i{ 0U }; i < time_tracks.size(); ++i)
    {
        // cout << "i : " << i << '\n';
        // print(grid, GRID_DIM, GRID_DIM);
        if(time_tracks[i].empty())
            continue;
        kill(grid, GRID_DIM, GRID_DIM, time_tracks[i]); 
        bool is_alive{ gen(grid, GRID_DIM, GRID_DIM) };
        if(!is_alive)
        {
            end_time = i;
            break;
        }
        else
        {
            end_time = i + 1;
        }
    }
    cout << end_time << '\n';
    return EXIT_SUCCESS;
}

