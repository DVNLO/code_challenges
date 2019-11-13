#include <array>
#include <cstdio>
// this is an outstanding example of why you should stop using explicit types.
// instread refer to the types as they're defined in the container itself.
// if you do it an alternative way, then you're supposing knowledge about
// how the standard library will work on the target architecture. 
int main()
{
    std::array<int, 5> a = { 1, 2, 3, 4, 5 };
    std::array<int, 5>::size_type const size = a.size();
    for(std::array<int, 5>::size_type i{ 0 }; i < size; ++i)
        printf("%d ", a[i]);
}
