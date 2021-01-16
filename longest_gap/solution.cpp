#include <vector>
#include <utility>
#include <iostream>

std::vector<std::pair<size_t, size_t>>
max_gap(std::vector<bool> const & vals)
// returns indicies of the maximum gap
// found in the provided vals. 
{
    std::vector<std::pair<size_t, size_t>> ret;
    std::size_t max_gap_len{ 0U };
    std::size_t const SIZE_VALS{ vals.size() };
    std::size_t j{ 0U };
    while(j < SIZE_VALS)
    {
        if(vals[j])
        {
            std::size_t const i{ j };
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
                std::pair<std::size_t, std::size_t> cur{ i, j };
                std::size_t const cur_gap_len{ cur.second - cur.first - 1 };
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

std::size_t 
len_gap(std::pair<std::size_t, std::size_t> const & gap)
// returns the length of a gap pair where the first and second values of the
// gap represent indexes. The gap length excludes the bounding indexes. So for
// an example gap ...1... the gap length is 0, ...11.... the gap length is 0,
// ...101... the gap length is 1. A gap may also be inverted, so an example gap
// ...0... has gap length 0, ...00.... has gap length 0, and ...010... has gap
// length 1. Gaps of length zero are considered degenerate.
{
    if(gap.first == gap.second)
    {
        return 0U;
    }
    else
    {
        return std::max(gap.first, gap.second) 
                - std::min(gap.first, gap.second) - 1;
    }
}

bool
max_gap(std::vector<bool> const & vals,
        std::size_t & max_gap_len,
        std::vector<std::pair<std::size_t, std::size_t>> & max_gap_idx_ranges)
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
        max_gap_len = len_gap(max_gap_idx_ranges.front());
    }
    if(max_gap_len == 0U)
    {
        max_gap_idx_ranges.clear();
    }
    return max_gap_len > 0U;
}

std::pair<std::size_t, std::size_t>
get_bounded_interval(std::vector<bool> const & vals, 
                     std::size_t const begin_idx)
// returns a bounding interval where the first and second indexes have
// equivalent values in vals and all indexes between first and second
// are not equal to the values at the first and second indexes. Note
// that the vals[begin_idx] value is used to determine the bounding 
// value and all elements in the middle will not equal the bounding
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
    if(end_idx < SIZE_VALS 
       && vals[begin_idx] == vals[end_idx])
    {
        return { begin_idx, end_idx };
    }
    else
    {
        return { begin_idx, begin_idx };
    }
}

std::vector<std::pair<std::size_t, std::size_t>>
get_max_gap_with_holes(std::vector<bool> const & vals,
                       std::size_t const max_gap_len,
                       bool const gap_val)
// returns a vector of maximum gap with hole(s) where each hole does not 
// exceed the max_gap_len, and a hole is a continuous run of gap_vals bounded
// by not gap_val's. For example a vals == 1001010 with max_gap_len 2 and 
// gap_val == 0 will return { { 0, 5} }; the trailing 0 is excluded.
{
    std::size_t const SIZE_VALS{ vals.size() };
    std::vector<std::pair<std::size_t, std::size_t>> max_gaps_with_holes;
    if(!SIZE_VALS)
    {
        return max_gaps_with_holes;
    }
    std::size_t k{ 0U };
    while(k < SIZE_VALS)
    {
        if(vals[k] == gap_val)
        {
            ++k;    // advance over elements of the gap_val
            continue;
        }
        else
        {
            // greedily maximize the cur_gap by iteratively advancing
            // the size of cur_gap until falling off the end of the vals vector
            // or not finding a larger gap or discovering a gap greater than 
            // the max_gap_len.
            std::pair<std::size_t, std::size_t> cur_gap{ k, k };
            std::pair<std::size_t, std::size_t> next_gap{ get_bounded_interval(vals, cur_gap.second) };
            while(next_gap.second < SIZE_VALS 
                  && len_gap(next_gap) > 0
                  && len_gap(next_gap) <= max_gap_len)
            {
                cur_gap.second = next_gap.second;
                next_gap = get_bounded_interval(vals, cur_gap.second);
            }
            if(max_gaps_with_holes.empty())
            {
                max_gaps_with_holes.push_back(cur_gap);
            }
            else
            {
                if(len_gap(cur_gap) > len_gap(max_gaps_with_holes.front()))
                {
                    max_gaps_with_holes.clear();
                    max_gaps_with_holes.push_back(cur_gap);
                }
                else if(len_gap(cur_gap) == len_gap(max_gaps_with_holes.front()))
                {
                    max_gaps_with_holes.push_back(cur_gap);
                }
            }
            if(next_gap.second == k)
            {
                ++k;    // degenerate gap discovered, move on.
            }
            else
            {
                // since the cur_gap.second == next_gap.second
                // or the len_gap(next_gap) > max_gap_len, and 
                // therefore can never be included, we can
                // advance to next_gap.second
                k = next_gap.second;
            }
        }
    }
    return max_gaps_with_holes;
}

bool
max_gap_with_holes(std::vector<bool> const & vals,
                   std::size_t & max_gap_with_holes_len,
                   std::vector<std::pair<std::size_t, std::size_t>> & max_gap_with_holes_idx_ranges,
                   std::size_t const max_gap_len,
                   bool const gap_val)
// returns true when there exists a maximum gap with holes in vals with size 
// greater than zero. The discovered max gap with holes length is output 
// through the max_gap_with_holes_len variable. A collection of max gaps with 
// holes index ranges are output through the max_gap_with_holes_idx_ranges 
// variable. Note that multiple max gaps with holes index ranges may be returned
// if there exits multiple ranges of equivalent maximum value.
{
    max_gap_with_holes_idx_ranges = get_max_gap_with_holes(vals, max_gap_len, gap_val);
    if(max_gap_with_holes_idx_ranges.empty())
    {
        max_gap_with_holes_len = 0U;
    }
    else
    {
        max_gap_with_holes_len = len_gap(max_gap_with_holes_idx_ranges.front());
    }
    return max_gap_with_holes_len > 0U;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<bool> vals(n);
    std::size_t max_hole_gap_len;
    std::size_t gap_val;
    std::cin >> max_hole_gap_len >> gap_val;
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
    std::cout << "max_gap_len == " << max_gap_len << '\n';
    for(auto max_gap_idx_range : max_gap_idx_ranges)
    {
        std::cout << "max_gap_idx_range[lhs_idx, rhs_idx] == [" 
                  << max_gap_idx_range.first << ", "
                  << max_gap_idx_range.second << ']'
                  << std::endl;
    }
    if(max_gap_idx_ranges.empty())
    {
        std::cout << "no max gap ranges found" << std::endl;
    }
    std::size_t max_gap_with_holes_len;
    std::vector<std::pair<std::size_t, std::size_t>> 
        max_gap_with_holes_idx_ranges;
    max_gap_with_holes(vals, max_gap_with_holes_len, 
        max_gap_with_holes_idx_ranges, max_hole_gap_len, gap_val);
    std::cout << "max_gap_with_holes_len == " << max_gap_with_holes_len << '\n';
    for(auto max_gap_with_holes_idx_range : max_gap_with_holes_idx_ranges)
    {
        std::cout << "max_gap_idx_range[lhs_idx, rhs_idx] == [" 
                  << max_gap_with_holes_idx_range.first << ", "
                  << max_gap_with_holes_idx_range.second << ']'
                  << std::endl;
    }
    if(max_gap_with_holes_idx_ranges.empty())
    {
        std::cout << "no max gap with holes found" << std::endl;
    }

}
