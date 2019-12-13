#include <bits/stdc++.h>
using namespace std;

void merge_sort(int * arr, 
		int const * const lower_bound, 
		int const * const upper_bound)
{
	if(!arr || lower_bound >= upper_bound)
		return;
	size_t const ARR_SIZE{ upper_bound - lower_bound };
	for(size_t i{ 0 }; i < ARR_SIZE; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	
	int const * const midpoint{ lower_bound + ((upper_bound - lower_bound) / 2) };
	size_t const LEFT_SIZE{ midpoint - lower_bound };
	int * left = new int[LEFT_SIZE];
	for(size_t i{ 0 }; i < LEFT_SIZE; ++i)
		left[i] = arr[i];
	merge_sort(left, left, left + LEFT_SIZE);
	
	size_t const RIGHT_SIZE{ upper_bound - midpoint };
	int * right = new int[upper_bound - midpoint];
	for(size_t i{ 0 }; i < RIGHT_SIZE; ++i)
		right[i] = arr[LEFT_SIZE + i];
	merge_sort(right, right, right + RIGHT_SIZE);
}

int main()
{
	int n;
	scanf("%d", &n);
	int * arr = new int[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	merge_sort(arr, arr, arr + n);
	for(int i = 0; i < n; ++i)
		printf("%d", arr[i]);

}
