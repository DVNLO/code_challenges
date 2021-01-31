#include <bits/stdc++.h>
using namespace std;

std::size_t
get_level_up_count(std::vector<int> scores, std::size_t const cutoff)
// returns the number of scores greater than the provided cutoff rank. 
{
    sort(begin(scores), end(scores), std::greater<>()); // descending
    std::size_t ret{ cutoff };  // search from the cutoff position 
    if(!scores[ret])    // 0 scores cannot level up
    {
        // advance left until discover of a non-zero score
        while(ret > 0 && scores[ret - 1] == 0)
        {
            --ret;
        }
    }
    else
    {
        // advance right while equal scores are discovered
        while(ret < scores.size() && scores[ret] == scores[ret - 1])
        {
            ++ret;
        }
    }
    return ret;
}

int main()
{
    std::size_t cutoff;
    std::size_t size;
    cin >> size >> cutoff;
    vector<int> scores(size);
    for(std::size_t i{ 0U }; i < size; ++i)
    {
        cin >> scores[i];
    }
    cout << get_level_up_count(scores, cutoff) << endl;
}