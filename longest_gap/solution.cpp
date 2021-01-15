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

bool
max_gap_with_holes(std::vector<bool> const & vals,
                   size_t & max_gap_with_holes_len,
                   std::vector<std::pair<size_t, size_t>> & max_gap_with_holes_idx_ranges,
                   size_t const max_hole_len,
                   bool const hole_val)
// returns the maximum gap found in vals where a gap is a continuous run of 
// hole_val bounded by !hole_val and no continuous sequence of hole_vals 
// exceeds max_hole_len. 
// For example with hole_val = false and max_hole_len = 0
// and vals = 1001 the max_gap_with_holes_len = 2
{

}

std::pair<std::size_t, std::size_t>
get_bounded_interval(std::vector<bool> const & vals, 
                     std::size_t const begin_idx)
// returns a bounding interval where the first and second indexes have
// equivalent values in vals and all indexes between first and second
// are not equal to the values at the first and second indexes. Note
// that the vals[begin_idx] value is used to determine the bounding 
// value and all elements in the middle will not equal lthe bounding
// value.
{
    std::size_t const SIZE_VALS{ vals.size() };
    if(begin_idx >= SIZE_VALS)
    {
        return { begin_idx, begin_idx };
    }
    std::size_t end_idx{ begin_idx + 1 };
    while(end_idx < SIZE_VALS 
          && vals[begin_idx] != vals[end_idx])
    {
        ++end_idx;
    }
    if(end_idx < SIZE_VALS)
    {
        return { begin_idx, end_idx };
    }
    else
    {
        return { begin_idx, begin_idx };
    }
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
