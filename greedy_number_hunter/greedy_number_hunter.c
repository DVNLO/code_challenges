#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


size_t
binary_search(int const val, int const * const arr, size_t const sz)
{
    size_t left_idx = 0;
    size_t right_idx = sz;
    while(left_idx < right_idx)
    {
        size_t mid_idx = left_idx + (right_idx - left_idx) / 2;
        if(val > arr[mid_idx])
        {
            left_idx = mid_idx;
        }
        else if(val < arr[mid_idx])
        {
            right_idx = mid_idx;
        }
        else
        {
            return mid_idx;
        }
    }
    return sz;
}

int 
main()
{
    size_t sz = (size_t)(INT_MAX);
    int * arr = (int *)(calloc(sz, sizeof(int)));
    if(!arr)
    {
        return EXIT_FAILURE;
    }
    for(int i = 0; i < (int)(sz); ++i)
    {
        arr[i] = i;
    }
    for(int i = 0; i < (int)(sz); ++i)
    {
        if(i % 10000 == 0)
        {
            printf("%d\n", i);
        }
        size_t idx = binary_search(i, arr, sz);
        if(idx >= sz || arr[idx] != i)
        {
            printf("%lu != %d\n", idx, i);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
