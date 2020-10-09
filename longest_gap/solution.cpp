#include <vector>
#include <utility>
#include <iostream>

std::vector<std::pair<size_t, size_t>>
max_gap(std::vector<bool> const & vals)
// returns indicies of the maximum gap
// found in the provided vals. 
{
    std::vector<std::pair<size_t, size_t>> ret;
    size_t max_gap_len{ 0U };
    size_t const SIZE_VALS{ vals.size() };
    size_t j{ 0U };
    while(j < SIZE_VALS)
    {
        if(vals[j])
        {
            size_t const i{ j };
            ++j;
            while(j < SIZE_VALS && !vals[j])
            {
                ++j;
            }
            if(j >= SIZE_VALS)
            {
                break;
            }
            else
            {
                std::pair<size_t, size_t> cur{ i, j };
                size_t const cur_gap_len{ cur.second - cur.first - 1 };
                if(cur_gap_len == max_gap_len)
                {
                    ret.push_back(cur);
                }
                else if(cur_gap_len > max_gap_len)
                {
                    max_gap_len = cur_gap_len;
                    ret.clear();
                    ret.push_back(cur);
                }
            }
        }
        else
        {
            ++j;
        }
    }
    return ret;
}

bool
max_gap(std::vector<bool> const & vals,
        size_t & max_gap_len,
        std::vector<std::pair<size_t, size_t>> & max_gap_idx_ranges)
// Determines the maximum gap in vals, where a gap is a 
// continuous run of false values beginning and ending
// with true values. For example a gap of 1 is 101, a gap
// of 2 is 1001, and so on. Returns true when the max_gap_len
// is greater than 0.
{
    max_gap_idx_ranges = max_gap(vals);
    if(max_gap_idx_ranges.empty())
    {
        max_gap_len = 0U;
    }
    else
    {
        std::pair<size_t, size_t> & tmp{ max_gap_idx_ranges[0] };
        max_gap_len = tmp.second - tmp.first - 1;
    }
    if(max_gap_len == 0U)
    {
        max_gap_idx_ranges.clear();
    }
    return max_gap_len > 0U;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<bool> vals(n);
    int val;
    for(size_t i{ 0U }; i < n; ++i)
    {
        std::cin >> val;
        vals[i] = static_cast<bool>(val);
    }
    for(size_t i{ 0U }; i < n; ++i)
    {
        std::cout << static_cast<int>(vals[i]) << ' ';
    }
    std::cout << '\n';
    size_t max_gap_len;
    std::vector<std::pair<size_t, size_t>> max_gap_idx_ranges;
    max_gap(vals, max_gap_len, max_gap_idx_ranges);
    for(auto max_gap_idx_range : max_gap_idx_ranges)
    {
        std::cout << "max_gap_len == " << max_gap_len << '\n';
        std::cout << "max_gap_idx_range[lhs_idx, rhs_idx] == [" 
                  << max_gap_idx_range.first << ", "
                  << max_gap_idx_range.second << ']'
                  << std::endl;
    }
    if(max_gap_idx_ranges.empty())
    {
        std::cout << "no ranges found" << std::endl;
        std::cout << "max_gap_len == " << max_gap_len << std::endl;
    }
}