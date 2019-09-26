#include <cstdlib>

int* merge(int arr_left[],int sz_left, int arr_right[], int sz_right){
    /* declaring an array using dynamic allocation of memory. 
        Merged the given two arrays into this third output Array */
    int const MERGED_SIZE{ sz_left + sz_right };
    int* arr_merged = new int [MERGED_SIZE];
    int l{ 0 };
    int r{ 0 };
    for(int i{ 0 }; i < MERGED_SIZE; ++i)
    {
        std::cout << l << ' ' << r << ' ' << i << '\n';
        if(l >= sz_left)
        {
            while(r < sz_right)
            {
                arr_merged[i] = arr_right[r];
                ++r;
                ++i;
            }
        }
        else if(r >= sz_right)
        {
            while(l < sz_left)
            {
                arr_merged[i] = arr_left[l];
                ++l;
                ++i;
            }
        }
        else
        {
            if(arr_left[l] >= arr_right[r])
            {
                arr_merged[i] = arr_left[l];
                ++l;
            }
            else
            {
                arr_merged[i] = arr_right[r];
                ++r;
            }
        }
    }
    std::cout << "end\n";
    return arr_merged;
}

int main()
{
	int arr_left[3] = { 2, 1, 3 };
	int arr_right[3] = { 4, 6, 5 };
	int* arr_merged = new int[6];
	arr_merged = merge(arr_left, 3, arr_right, 3);
	int arr_merge_control[] = { 1, 2, 3, 4, 5, 6 };
	for(int i = 0; i < 6; ++i)
	{
		if(arr_merged[i] != arr_merge_control[i])
		{
			std::exit(EXIT_FAILURE);
		}
	}
}