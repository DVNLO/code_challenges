// This was a great problem. I was not able to 
// intuit the solution directly by observing the sum
// pattern. Next time I'll spend more time trying
// to intuit a solution directly, but the more
// labor intensive method did lead to the same solution.
// I developed two arithmetic series. The first for 
// computing the left most value in the triangle.
// and then the next arithmetic series for the row 
// sum. 
// So, the sum to compute the first value of the 
// row element r_n
// r_n = n^2 - n + 1
// Then solving for the row sum S_r_n
// S_r_n = n(r_n) + n^2 - n = n^3
long long rowSumOddNumbers(unsigned n)
{
  if(n == 1)
    return 1LL;
  long long r{ static_cast<long long>(n) };
  long long r2{ r * r };
  if(r2 <= r)
    return -1;
  long long r3{ r2 * r };
  if(r3 <= r2)
    return -1;
  else
    return r3;
}
