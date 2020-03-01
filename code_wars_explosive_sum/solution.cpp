#include <bits/stdc++.h>

using ull = unsigned long long;

ull exp_sum(unsigned int s) 
{
  std::vector<std::vector<ull>> pkn_table(s + 1, 
                                          std::vector<ull>(s + 1, 0));
  pkn_table[0][0] = 1ULL;
  // pk(n) = pk(n − k) + pk−1(n − 1)
  // with initial values p0(0) = 1 and pk(n) = 0 if n ≤ 0 or k ≤ 0 and n and k are not both zero
  for(size_t n{ 1 }; n <= s; ++n)
  {
    for(size_t k{ 1 }; k <= n; ++k)
    {
      if(n - k < 0)
        continue;
      pkn_table[n][k] = pkn_table[n - k][k] + pkn_table[n - 1][k - 1];
      std::cout << n << ' ' << k << ' ' << pkn_table[n][k] << '\n';
    }
  }
  ull ways{ 0 };
  for(size_t k{ 1 }; k <= s; ++k)
  {
    ways += pkn_table[s - k][k] + pkn_table[s - 1][k - 1];
  }
  return ways;
}

int main()
{
  std::cout << exp_sum(4) << std::endl;
}
