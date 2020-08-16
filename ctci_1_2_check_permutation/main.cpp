#include <bits/stdc++.h>

// note that this can be improved to not use dynamic memory
// since the size of the character in our string is known
// at compile time, therefore we can initialize the counts
// arrays to be static.

uint32_t * get_char_counts(std::string const & s)
{
    size_t const SYMBOL_COUNTS{ 256U };
    uint32_t * counts = new uint32_t[SYMBOL_COUNTS]{ 0U };
    size_t const SIZE_S{ s.size() };
    for(size_t i{ 0U }; i < SIZE_S; ++i)
    {
        ++counts[s[i]];
    }
    return counts;
}

bool check_permutation(std::string const & lhs,
                       std::string const & rhs)
// returns true if lhs and rhs strings are permutations
{
    bool ret{ true };
    size_t const SYMBOL_COUNT{ 256U };
    uint32_t * lhs_counts{ get_char_counts(lhs) };
    uint32_t * rhs_counts{ get_char_counts(rhs) };
    for(size_t i{ 0 }; i < SYMBOL_COUNT; ++i)
    {
        if(lhs_counts[i] != rhs_counts[i])
        {
            ret = false;
            break;
        }
    }
    delete lhs_counts;
    delete rhs_counts;
    return ret;
}

int main()
{
    std::string lhs;
    std::string rhs;
    std::cin >> lhs >> rhs;
    if(check_permutation(lhs, rhs))
    {
        std::cout << "permutation";
    }
    else
    {
        std::cout << "not permutation";
    }
    std::cout << std::endl;
}

