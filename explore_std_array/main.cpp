#include <array>
#include <cstdio>

int main()
{
    std::size_t const SIZE{ 5 };
    std::array<int, SIZE> arr { 0 };
    for(std::size_t i{ 0 }; i < SIZE; ++i)
    {
        std::printf("%d ", arr[i]);
    }
    std::putc('\n', stdout);

    /* By default, a c-style array will not initialize it's
     * values. This leads to garbage values in the index positions.
     * However, an array can be zero initialized by specifying the
     * fist x characters you would like to specify and the remainder
     * of the indexes will be zero initialized. In parallel, the same
     * functionality seems to occur for our std::array.
     */
    int carr[SIZE];
    for(std::size_t i{ 0 }; i < SIZE; ++i)
    {
	std::printf("%d ", carr[i]);
    }
    std::putc('\n', stdout);
}
