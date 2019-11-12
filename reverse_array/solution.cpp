#include <cstdio>
#include <cstdlib>

inline bool is_expected_rc(int const rc_actual,
                            int const rc_expected,
                            char const * const msg)
{
    if(rc_actual != rc_expected)
    {
        std::puts(msg);
        return false;
    }
    else
    {
        return true;
    }
}

void reverse(int * arr, size_t const size)
{
    int tmp;
    int j;
    size_t midpoint = size / 2;
    for(size_t i = 0; i < midpoint; ++i)
    {
        j = size - i - 1;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main()
{
    int size;
    int rc = std::scanf("%d", &size);
    if(!is_expected_rc(rc, 1, "failed to read size"))
        std::exit(EXIT_FAILURE);
    if(size <= 0)
    {
        std::puts("domain error size must be greater than zero");
        std::exit(EXIT_FAILURE);
    }
    int * arr = new int[size];
    for(size_t i = 0; i < size; ++i)
    {
        rc = std::scanf("%d", (arr + i));
        if(!is_expected_rc(rc, 1, "failed to read arr[i]"))
            std::exit(EXIT_FAILURE);
    }
    reverse(arr, size);
    for(size_t i = 0; i < size; ++i)
    {
        rc = std::printf("%d ", arr[i]);
        if(!is_expected_rc(rc, 2, "failed to print arr[i]"))
            std::exit(EXIT_FAILURE);
    }
}

