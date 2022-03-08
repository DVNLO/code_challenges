#include <bits/stdc++.h>
using namespace std;

template<unsigned long long n>
struct factorial
{
    enum { val = n * factorial<n - 1>::val };
};

template<>
struct factorial<0>
{
    enum { val = static_cast<unsigned long long>(1) };
};


int
main()
{
    printf("factorial<7>::value == %llu\n", factorial<static_cast<unsigned long long>(6)>::val);
}
