/* The following generates all permutations of a provided set s 
 */
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>


void generate_permutations(std::vector<std::string> & permutations, 
                            std::unordered_set<char> & S, 
                            std::string permutation = std::string())
{
    if(S.empty())
    {
        permutations.push_back(permutation);
        return;
	}
	else
	{
		for(auto const s : S)
		{
			std::unordered_set<char> S_prime{ S };
			S_prime.erase(s);
			std::string permutation_prime{ permutation + s };
			generate_permutations(permutations, S_prime, permutation_prime);
		}
	}
}


std::vector<std::string> generate_all_permutations(std::unordered_set<char> S)
{
	std::vector<std::string> permutations;
	generate_permutations(permutations, S);
	return permutations;
}

int main()
{
	std::unordered_set<char> S;
    int end = static_cast<char>('j');
    for(int i = static_cast<int>('a'); i <= end; ++i)
    {
        S.insert(static_cast<char>(i));
    }
	std::vector<std::string> permutations = generate_all_permutations(S);
	for(auto const permutation : permutations)
	{
		puts(permutation.c_str());
	}
}
