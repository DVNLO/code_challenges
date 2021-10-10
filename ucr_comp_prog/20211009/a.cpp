#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<vector<T>>
all_pairs_shortest_path(vector<vector<T>> const & graph)
{
    size_t const vertex_count{ graph.size() };
    vector<vector<T>> costs(vertex_count, 
            vector<T>(vertex_count, numeric_limits<T>::max()));
    for(size_t i{ 0U }; i < vertex_count; ++i)
    {
        for(size_t j{ 0U }; j < vertex_count; ++j)
        {
            // find the min path
            // i --- k --- j
        }
    }

    return costs;
}


int main()
{
    long n;  // num cities 
    long m;  // num bi-directional roads
    long k;  // num cities with storage
    // pay 1 ruple per distance between cities
    //
    // GOAL : pay minimum possible amount of rubles for 
    // flour delivery between city with 
    // storage and city with bakery
    // bakery and storage cannot be in same city
    cin >> n >> m >> k;
    if(k <= 0)
    {
        // not possible to minimize cost if no 
        // storage exists
        cout << "-1" << endl;
        return;
    }
    vector<vector<long>> board(n, vector<long>(n, -1));
    vector<vector<long>> costs(board);
    for(long i = 0; i < m; ++i)
    {
        long u; // city idx
        long v; // city idx
        long l; // distance km
        cin >> u >> v >> l;
        board[u - 1][v - 1] = l;
    }
    vector<long> storages(k);
    for(long i = 0; i < k; ++i)
        cin >> storages[i];
    // pick a bakery and compute the shortest paths
    // to all storages
    // a bakery has a shortest path to storage s_i
    // all pairs shortest paths between bakeries and storage.
    for(long i = 0; i < n; ++i) // bakery b
    {
        for(long j = 0; j < k; ++j) // storage s
        {
            the goal is to find the min cost from b to 

}
