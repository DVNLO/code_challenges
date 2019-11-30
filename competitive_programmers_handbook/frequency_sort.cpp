#include <cstdio>
#include <cstdlib>
#include <cstring>

unsigned * frequency_sort(unsigned A[], size_t const size)
{
	if(!size)
		return nullptr;
	unsigned max = A[0];
	for(size_t i{ 1 }; i < size; ++i)
	{
		if(A[i] > max)
			max = A[i];
	}
	size_t const COUNT_SIZE{ max + 1 };
	unsigned * counts = new unsigned[COUNT_SIZE];
	for(size_t i{ 0 }; i < COUNT_SIZE; ++i)
		counts[i] = 0;
	for(size_t i{ 0 }; i < size; ++i)
	{
		++counts[A[i]];
	}
	unsigned * sorted = new unsigned[size];
	unsigned * target = sorted;
	for(size_t i{ 0 }; i < COUNT_SIZE; ++i)
	{
		while(counts[i])
		{
			*target = static_cast<unsigned>(i);
			++target;
			--counts[i];
		}
	}
	delete counts;
	return sorted;
}

int main()
{
	size_t const SIZE{ 8U };
	unsigned A[] = { 1, 3, 6, 9, 9, 3, 5, 9 };
	unsigned * B = frequency_sort(A, SIZE);
	for(size_t i{ 0 }; i < SIZE; ++i)
		printf("%d ", B[i]);
	printf("\n");
}
