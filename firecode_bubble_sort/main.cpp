#include <cstdlib>


int* bubble_sort_array(int arr[], int size)
{
    if(!arr || size < 0) // invalid pre-conditions
    {
        return nullptr;
    }
    else if(size <= 1)  // trivial cases
    {
        return arr;
    }
    std::size_t max_idx;
    int tmp_swap;
    for(std::size_t i = size - 1; i > 0; --i)
    {
        max_idx = 0;
        for(std::size_t j = 0; j < i; ++j)
        {
            if(arr[max_idx] < arr[j])
            {
                max_idx = j;
            }
        }
        if(arr[max_idx] > arr[i])
        {
            tmp_swap = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = tmp_swap;
        }
    }
    return arr;
}

int main()
{
	std::size_t const SIZE{ 3 }; 
	int arr[] = { 2, 1, 3 };
	bubble_sort_array(arr, SIZE);
	int sorted_arr[] = { 1, 2, 3 };
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		if(arr[i] != sorted_arr[i])
		{
			std::exit(EXIT_FAILURE);
		}
	}
}
