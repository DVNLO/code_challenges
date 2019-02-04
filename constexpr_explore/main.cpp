/* The following program was an exploration of constexpr array initialization,
 * but I wasn't able to get it to compile, after 15 mins or so. At this point,
 * I will move on, and hopefully something in A Tour of C++ will discsuss this
 * Code found on stackoverflow.
 */

#include <iostream>
#include <array>
#include <cstdint>

using namespace std;

template<typename T, T N>
constexpr auto make_constexpr_array(std::integral_constant<T, N>)
{
    std::array<int,N> result = {};
    for (int i = 0; i < N; ++i)
        result[i] = (3*i - 1)/2;
    return result;
}

int main()
{
    constexpr auto arr = make_constexpr_array(std::integral_constant<int, 6>{});
    static_assert(arr[0] == 0);
    static_assert(arr[1] == 1);
    static_assert(arr[2] == 2);
    static_assert(arr[3] == 4);
    static_assert(arr[4] == 5);
    static_assert(arr[5] == 7);
}
