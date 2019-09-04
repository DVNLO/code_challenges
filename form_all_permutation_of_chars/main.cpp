#include <cstdio>
#include <string>
#include <unordered_set>

void form_all_permutations(std::string const & chars, 
                           std::string const & current_str,
                           std::unordered_set<std::string> & permutations)
{
    if(!permutations.count(current_str))
    {
        std::printf("%s\n", current_str.c_str());
        permutations.insert(current_str);
    }
    std::size_t SIZE{ chars.size() };
    for(std::size_t i = 0; i < SIZE; ++i)
    {
        std::string next_str{ current_str + chars[i] };
        std::string next_chars{ chars };
        next_chars.erase(i, 1);
        form_all_permutations(next_chars, next_str, permutations);
    }
}

int main(int argc, char * argv[])
{
    std::string chars{ "danielvyenielo" };
    std::unordered_set<std::string> permutations;
    std::string current_str;
    form_all_permutations(chars, current_str, permutations);
}
