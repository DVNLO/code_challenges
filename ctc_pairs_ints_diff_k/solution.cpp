#include <cstdio>
#include <unordered_set>
using namespace std;

int count_pairs_with_diff(int A[], int const size, int k)
{
	int pair_count{ 0 };
	unordered_set<int> vals;
	for(int i{ 0 }; i < size; ++i)
		vals.insert(A[i]);
	for(int i{ 0 }; i < size / 2; ++i)
	{
		if(vals.count(A[i] + k))
		{
			printf("%d %d\n", A[i], A[i] + k);
			++pair_count;
		}
		if(vals.count(A[i] - k))
		{
			printf("%d %d\n", A[i], A[i] - k);
			++pair_count;
		}
	}
	return pair_count;
}

int main()
{
	int const SIZE{ 5 };
	int A[SIZE] = { 2, 4, 5, 1, 7 };
	int const k{ 3 };
	printf("%d\n", count_pairs_with_diff(A, SIZE, k));
}
