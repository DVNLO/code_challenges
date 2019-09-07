#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void print(std::vector<int> const & source)
{
    for(int const & val : source)
    {
        std::cout << val << ' ';
    }
}

void merge(std::vector<int> const & left_source,
           std::vector<int> const & right_source,
           std::vector<int> & target)
{
    std::size_t const TARGET_SIZE{ target.size() };
    std::size_t const LEFT_SIZE{ left_source.size() };
    std::size_t const RIGHT_SIZE{ right_source.size() };
    if(LEFT_SIZE + RIGHT_SIZE != TARGET_SIZE)
    {
        return;
    }
    std::size_t left_idx{ 0 };
    std::size_t right_idx{ 0 }; 
    for(std::size_t i = 0; i < TARGET_SIZE;)
    {
        if(left_idx == LEFT_SIZE) // copy remainder from the right
        {
            while(right_idx < RIGHT_SIZE)
            {
                target[i] = right_source[right_idx];
                ++right_idx;
                ++i;
            }
        }
        else if(right_idx == RIGHT_SIZE)    // copy remainder from the left
        {
            while(left_idx < LEFT_SIZE)
            {
                target[i] = left_source[left_idx];
                ++left_idx;
                ++i;
            }
        }
        else    // copy the i-th max from the left xor right
        {
            if(left_source[left_idx] <= right_source[right_idx])
            {
                target[i] = left_source[left_idx];
                ++left_idx;
            }
            else
            {
                target[i] = right_source[right_idx];
                ++right_idx;
            }
            ++i;
        }
    }
}

void copy(std::vector<int> const & source,
          std::size_t const source_start_idx,
          std::vector<int> & target,
          std::size_t const target_start_idx,
          std::size_t const count)
{
    std::size_t source_idx{ source_start_idx };
    std::size_t target_idx{ target_start_idx };
    for(std::size_t i = 0; i < count; ++i)
    {
        target[target_idx] = source[source_idx];
        ++target_idx;
        ++source_idx;
    }
}


/* Using indexes for this problem proved to be more challenging than I imagined.
 * Nevertheless, as always followig DJIKSTRA's recommendation of always using 
 * an integer which points to the index one past the end of the array is 
 * exceptionally helpful in avoiding the "off by one errror".
 * In addition to the indexing issue index translation from this frame to the 
 * calling frame was initially a challenging bug to catch. When I started my 
 * indexes were not being called relative to the current frame, but were kept
 * absolute to the original calling frame. This caused the indexes to become 
 * misaligned, which broke execution due to a segmentation fault. Overall, I
 * think this was an excellent challenge in terms of thought, but If I could
 * do it over I would not use indexes, and would now prefere to use the standard
 * libraries iterators and copy function rather than re-implementing the functions
 * myself.
 */
void merge_sort(std::vector<int> & values, 
                std::size_t const left_idx, 
                std::size_t const right_idx)
{
    if(right_idx <= left_idx || right_idx - left_idx <= 1)
    {
        return;
    }
    std::size_t const middle_idx{ left_idx + ((right_idx - left_idx) / 2) };
    
    std::size_t const LEFT_SIZE{ middle_idx - left_idx };
    std::vector<int> left_values(LEFT_SIZE);
    copy(values, left_idx, left_values, 0, LEFT_SIZE);
    merge_sort(left_values, 0, LEFT_SIZE);
    
    std::size_t const RIGHT_SIZE{ right_idx - middle_idx };
    std::vector<int> right_values(RIGHT_SIZE);
    copy(values, middle_idx, right_values, 0, RIGHT_SIZE);
    merge_sort(right_values, 0, RIGHT_SIZE);
    
    merge(left_values, right_values, values);
}


int main() 
{
    int32_t SIZE{ -1 };
    std::cin >> SIZE;
    if(!std::cin.good() || SIZE < 0)
    {
        exit(EXIT_FAILURE);
    }
    else if(SIZE <= static_cast<std::size_t>(1))  // trivial cases
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        std::vector<int> values(SIZE);
        for(std::size_t i = 0; i < SIZE; ++i)
        {
            if(!std::cin.good())
            {
                exit(EXIT_FAILURE);
            }
            std::cin >> values[i];
        }
        merge_sort(values, 0, SIZE);
        print(values);
    }
    return 0;
}
