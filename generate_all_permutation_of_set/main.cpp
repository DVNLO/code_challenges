/* The following generates all permutations of a provided set s 
 */
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>


void generate_permutations(std::vector<std::string> & permutations, std::unordered_set<char> & S, std::string permutation = default)
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
			permutation += s;
			generate_permutations(permutations, S_prime, permutation);
		}
	}
}


std:vector<std::string> generate_all_permutations(std::unordered_set<char> const & S)
{
	std::vector<std::string> permutations;
	generate_permutations(permutations, S);
	return permutations;
}

int main()
{
	std::unordered_set<char> S { '1', '2', '3' };
	std::vector<std::string> permutations = generate_all_permutations(S);
	for(auto const permutation : permutations)
	{
		puts(permutation.c_str());
	}
}
