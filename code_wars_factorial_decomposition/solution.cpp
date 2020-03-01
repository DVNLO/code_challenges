#include <string>

// Returns a vector of primes generated from 
// 0 to n, inclusive. Eg: { 2, 3, 5, 7, ... }
std::vector<int> generate_primes(int const n)
{
  std::vector<int> primes;
  if(n < 2)
    return primes;
  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for(int i{ 2 }; i <= n; ++i)
  {
    if(!is_prime[i])
      continue;
    primes.emplace_back(i);
    for(int j{ i + i}; j <= n; j += i)
      is_prime[j] = false;
  }
  return primes;
}

std::string decomp(int n) 
{
  std::string ret;
  if(n < 2)
    return ret;
  std::vector<int> primes{ generate_primes(n) };
  size_t const PRIMES_SIZE{ primes.size() };
  std::map<int, int> factor_counts;

  for(int i{ 2 }; i <= n; ++i)  // all terms in n!
  {
    int k{ i };
    for(size_t j{ 0 }; 
        j < PRIMES_SIZE && primes[j] <= i; 
        ++j)  // iterate over primes less than term
    {
      int factor_count{ 0 };
      while(k > 1 && k % primes[j] == 0)  // divde prime factors from term
      {
        k /= primes[j];
        ++factor_count;
      }
      if(factor_counts.count(primes[j]))  // increment factor count
        factor_counts[primes[j]] += factor_count;
      else
        factor_counts[primes[j]] = factor_count;
    }
  }
  // prepare output string
  static std::string const UP_CARROT{ "^" };
  static std::string const MULT_SUFFIX{ " * " };
  for(auto const factor_count : factor_counts)
  {
    ret += std::to_string(factor_count.first);
    if(factor_count.second > 1)
      ret += UP_CARROT + std::to_string(factor_count.second);
    ret += MULT_SUFFIX;
  }
  ret.resize(ret.size() - MULT_SUFFIX.size());
  return ret;
}
