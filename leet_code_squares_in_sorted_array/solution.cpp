// This was an instructive practice problem within which I was able to 
// review the merge procedure implementation, but with an interesting 
// twist of using reverse iteration in one half of the array.
// In addition I found a very insightful post on stack overflow regarding,
// reverse iteration bounds checking.
// https://stackoverflow.com/questions/3623263/reverse-iteration-with-an-unsigned-loop-variable
// It's not the accepted solution but one of the higher voted solutions
// recommends allowing the underflow to occur and simply checking if the 
// underflow then results in a value greater than the size of the array.
// There is no edge case here because even if the array has the same size as the
// max unsigned val it will not be less than, so it's safe. Pretty insightful observation.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        size_t A_SIZE{ A.size() };
        size_t i{ 0U };
        while(i < A_SIZE 
              && A[i] < 0)
        {
            ++i;
        }
        vector<int>B{ A };
        if(i > 0U)   // there exists negative vals in A
        {
            for(size_t j{ 0U }; j < i; ++j)
            {
                A[j] = abs(A[j]);
            }
            size_t j = i - 1;	// reverse iterator into the negative portion of the array
            size_t k = i;	// forward iterator into the positive portion of the array
            size_t l{ 0U };
            // genius check on the wrap around. for unsigned reverse iteration!
            while(j < A_SIZE 
                  && k < A_SIZE)	// since the sub arrays are both sorted we can merge in linear time
            {
                if(A[j] < A[k])
                {
                    B[l] = A[j];
                    --j;
                }
                else
                {
                    B[l] = A[k];
                    ++k;
                }
                ++l;
            }
            while(j < A_SIZE)	// if the two subarrays aren't equal we need to pull from either the negative
            {
                B[l] = A[j];
                --j;
                ++l;
            }
            while(k < A_SIZE)	// or the positive subarray.
            {
                B[l] = A[k];
                ++k;
                ++l;
            }
        }
        for(size_t m{ 0U }; m < A_SIZE; ++m)	// irregardless of containing a negative sub array we must still complete the squares.
        {
            B[m] *= B[m];
        }
        return B;
    }
};
