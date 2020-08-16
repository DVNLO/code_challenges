#include <bits/stdc++.h>

bool is_unique(std::string const & s)
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

