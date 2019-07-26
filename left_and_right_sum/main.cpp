/* Given an array A = {1, 2, 3, 4, 6}
 * Return the first index position where the sum of values with indices
 * less than the current index is equal to the sum of values with incicies
 * greater than the current index.
 */

#include <vector>
#include <iostream>

size_t index_of_balanced_sum(std::vector<int> const & A)
{
    int left_sum{ 0 };
    int right_sum{ 0 };
    auto const size{ A.size() };

    for(size_t i = 0; i < size; ++i)
    {
        right_sum += A[i];
    }
    for(size_t i = 0; i < size; ++i)
    {
        int const val = A[i];
        right_sum -= val;
        if(left_sum == right_sum)
        {
            return i;
        }
        left_sum += val;
    }
    if(left_sum == right_sum)
    {
        return size - 1;
    }
    else
    {
        return -1;  // no index found
    }
}

int main()
{
    std::vector<int> A = { 1, 2, 3, 4, 6 };
    std::cout << index_of_balanced_sum(A) << '\n';
    std::vector<int> B = { 6, 4, 3, 2, 1 };
    std::cout << index_of_balanced_sum(B) << '\n';
}