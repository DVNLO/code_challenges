#include <bits/stdc++.h>
using namespace std;

unsigned const GRID_DIM{ 5U };

set<pair<unsigned, unsigned>>
kill(set<pair<unsigned, unsigned>> const & cells, unsigned const x)
{
    set<pair<unsigned, unsigned>> ret;
    unsigned transform[10] = { 4, 3, 2, 1, 0, 0, 1, 2, 3, 4 };
    for(auto const cell : cells)
    {
        if(cell.first == transform[x - 1]
           || cell.second == transform[x - 1])
        {
            continue;
        }
        else
        {
            ret.insert(cell);
        }
    }
    return ret;
}

set<pair<unsigned, unsigned>>
gen(set<pair<unsigned, unsigned>> const & cells)
{
    set<pair<unsigned, unsigned>> ret;
    for(auto const cell : cells)
    {
        ret.insert(cell);
        if(cell.first - 1 < cell.first)
            ret.insert({cell.first - 1, cell.second});
        if(cell.first + 1 < GRID_DIM)
            ret.insert({cell.first + 1, cell.second});
        if(cell.second - 1 < cell.second)
            ret.insert({cell.first, cell.second - 1});
        if(cell.second + 1 < GRID_DIM)
            ret.insert({cell.first, cell.second + 1});
    }
    return ret;
}

void
print(set<pair<unsigned, unsigned>> cells)
{
    unsigned grid[5][5]{ 0U };
    for(auto const cell : cells)
    {
        grid[cell.first][cell.second] = true;
    }
    for(int i{ 0 }; i < 5; ++i)
    {
        for(int j{ 0 }; j < 5; ++j)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    int n;
    cin >> n;
    set<pair<unsigned, unsigned>> cells;
    for(unsigned i{ 0 }; i < GRID_DIM; ++i)
    {
        for(unsigned j{ 0 }; j < GRID_DIM; ++j)
        {
            cells.insert({i, j});
        }
    }
    unsigned i{ 0U };
    vector<vector<unsigned>> time_tracks(n);
    for(int i = 0; i < n; ++i)
    {
        unsigned t;
        unsigned x;
        cin >> t >> x;
        time_tracks[t].push_back(x);
    }
    unsigned t{ 1U };
    for(auto i{ 0U }; i < n; ++i)
    {
        if(time_tracks[i].empty())
            continue;
        for(auto const track : time_tracks[i])
        {
            cells = kill(cells, track);
        }
        cells = gen(cells);
        if(cells.empty())
        {
            t = i;
            break;
        }
        else
        {
            t = i + 1;
        }
    }
    cout << t << '\n';
    return EXIT_SUCCESS;
}

