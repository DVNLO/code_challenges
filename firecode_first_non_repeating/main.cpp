#include <array>
#include <limits>

/* The following is a solution to firecode prompt first non repeating.
 * The objective is to return the first non repeating character from a provided
 * argument string str. My solution utilizes the numeric limits library to 
 * build a std::array of zero initialized values. The str is iterated through
 * and the corresponding array index is incremented. Finally, a linear search 
 * is conducted through the str searching for the first character with only 
 * one occurence. That character is subsequently returned. 
 */
char first_non_repeating(string str)
{
    std::size_t const STR_SIZE{ str.size() };
    std::size_t const UNIQUE_CHAR_COUNT{ std::numeric_limits<unsigned char>::max() + 1 };
    std::array<std::size_t, UNIQUE_CHAR_COUNT> char_to_count;
    std::size_t const INITIAL_COUNT{ static_cast<std::size_t>(0) };
    for(std::size_t i = 0; i < UNIQUE_CHAR_COUNT; ++i)  // initialize
    {
        char_to_count[i] = INITIAL_COUNT;
    }
    for(std::size_t i = 0; i < STR_SIZE; ++i)   // count
    {
        ++char_to_count[static_cast<std::size_t>(str[i])];
    }
    for(std::size_t i = 0; i < STR_SIZE; ++i)  // search
    {
        if(char_to_count[static_cast<std::size_t>(str[i])] == 1)
        {
            return str[i];
        }
    }
    return '0';
}
