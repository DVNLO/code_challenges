// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
double power(double x, int n)
{
    if(n < 0)
    {
        n = std::abs(n);
        double ret{ static_cast<double>(1) };
        for(int i = 0; i < n; ++i)
        {
            ret /= x;
        }
        return ret;
    }
    else if(!n) // n == 0
    {
        return static_cast<double>(1);
    }
    else // -> n > 0
    {
        double ret{ static_cast<double>(1) };
        for(int i = 0; i < n; ++i)
        {
            ret *= x;
        }
        return ret;
    }
}
