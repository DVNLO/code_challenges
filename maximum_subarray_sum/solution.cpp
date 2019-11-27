#include <algorithm>
#include <cstdio>
#include <limits>

int max_subarray_sum_ON3(int A[], size_t const size)
{
	int max_subarray_sum{ std::numeric_limits<int>::min() };
	for(size_t i{ 0U }; i < size; ++i)
	{
		for(size_t j{ i + 1 }; j < size; ++j)
		{
			int subarray_sum{ 0 };
			for(size_t k{ i }; k < j; ++k)
			{
				subarray_sum += A[k];
			}
			if(subarray_sum > max_subarray_sum)
				max_subarray_sum = subarray_sum;

		}
	}
	return max_subarray_sum;
}

int max_subarray_sum_ON2(int A[], size_t const size)
{	
	int max_subarray_sum{ std::numeric_limits<int>::min() };
	int subarray_sum;
	for(size_t i{ 0U }; i < size; ++i)
	{
		subarray_sum = A[i];
		for(size_t j{ i + 1 }; j < size; ++j)
		{
			subarray_sum += A[j];
			if(subarray_sum > max_subarray_sum)
				max_subarray_sum = subarray_sum;
		}
	}
	return max_subarray_sum;
}

// Kadane's algorithm!
// https://www.youtube.com/watch?v=86CQq3pKSUw
int max_subarray_sum_ON1(int A[], size_t const size)
{
	int max_subarray_sum{ 0 };
	int subarray_sum{ 0 };
	for(size_t i{ 0U }; i < size; ++i)
	{
		subarray_sum = std::max(A[i], subarray_sum + A[i]);
		max_subarray_sum = std::max(max_subarray_sum, subarray_sum);
	}
	return max_subarray_sum;

}

int main()
{
	size_t size{ 8U };
	int A[size] = { -1, 2, 4, -3, 5, 2, -5, 2 };
	int max = max_subarray_sum_ON3(A, size);
	printf("%d\n", max);
	max = max_subarray_sum_ON2(A, size);
	printf("%d\n", max);
	max = max_subarray_sum_ON1(A, size);
	printf("%d\n", max);
	return 0;
}
