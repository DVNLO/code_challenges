#include <bits/stdc++.h>

// while reviewing this problem the bool provided some influential
// insights for improving my solution. First, you need to clarify
// what the width of the symbols in the string is. Are they 
// ASCII or Unicode symbols? Recall that unicode symbols are 16 bits
// wide therefore they have 2^16 == 65536 permutations. Whereas
// extended ASCII is only 2^8 == 256 symbols. 

// Second, since we are only checking if s is unique, we can use a 
// boolean array for the counts. 

// third, we can take this a step further and use a bitset.
// https://www.youtube.com/watch?v=jqJ5s077OKo 

// fourth, if the length of the string is more than the number of
// symbols in the language their must be a duplicate in the string.

bool is_unique_og(std::string const & s)
{
    bool ret{ true };
    size_t const UNIQUE_SYMBOL_COUNT{ 256U };
    uint8_t counts[UNIQUE_SYMBOL_COUNT];
    for(size_t i{ 0U }; i < UNIQUE_SYMBOL_COUNT; ++i)
    {
        counts[i] = 0U;
    }
    size_t const SIZE_S{ s.size() };
    for(size_t i{ 0U }; i < SIZE_S; ++i)
    {
        uint8_t & val{ counts[static_cast<size_t>(s[i])] };
        if(val)
        {
            ret = false;
            break;
        }
        else
        {
            ++val;
        }
    }
    return ret;
}

// the following is an implementation following solution review leveraging
// the helpful edge cases and using a more memory effecient datastructure
// the bitset. 

bool is_unique(std::string const & s)
{
    size_t constexpr UNIQUE_SYMBOL_COUNT{ 256U };
    size_t const SIZE_S{ s.size() };
    if(SIZE_S > UNIQUE_SYMBOL_COUNT)
    {
        return false;
    }
    std::bitset<UNIQUE_SYMBOL_COUNT> counts;    // initialized to 0 by default
    size_t cur_symbol;
    for(size_t i{ 0U }; i < SIZE_S; ++i)
    {
        cur_symbol = static_cast<size_t>(s[i]);
        if(counts.test(cur_symbol)) // -> cur_symbol is a duplicate 
        {
            return false;
        }
        else
        {
            counts.set(cur_symbol);
        }
    }
    return true;
}


int main()
{
    std::string s;
    std::cin >> s;
    if(is_unique(s))
    {
        std::cout << "unique";
    }
    else
    {
        std::cout << "not unique";
    }
    std::cout << std::endl;
}
