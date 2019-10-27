#include <cmath>
#include <cstdio>
#include <set>
#include <vector>

std::set<int> sieve_eratosthenes(unsigned const n)
{
	std::size_t const UPPER_BOUND{ n + 1 };
	std::size_t const MAX_I{ static_cast<size_t>(std::sqrt(UPPER_BOUND)) };
	std::vector<bool> is_prime(UPPER_BOUND, true);
	is_prime[0] = false;
	is_prime[1] = false;
	std::set<int> primes;
	for(std::size_t i{ 2 }; i <= MAX_I; ++i)
	{
		if(is_prime[i])
		{
			primes.insert(i);
			for(std::size_t j{ i * i }; j <= UPPER_BOUND; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	for(std::size_t i{ MAX_I + 1 }; i < UPPER_BOUND; ++i)
	{
		if(is_prime[i])
			primes.insert(i);
	}
	return primes;
}

int main(int argc, char const * const argv[])
{
	int n;
	std::scanf("%d", &n);
	std::set<int> primes = sieve_eratosthenes(n);
	for(auto prime : primes)
		printf("%d ", prime);
}
