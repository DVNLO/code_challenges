#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& A) {
        const unsigned size = A.size();
        for(unsigned i = 0; i < size; ++i)
            A[i] = A[i] * A[i];
        sort(A.begin(), A.end());
        return A;
    }
};

int main()
{
	Solution prompt;
	vector<int> A = { -4 , -1, 0, 3, 10 };
	vector<int> B = prompt.sortedSquares(A);
	for(int i = 0; i < 5; ++i)
		cout << B[i] << ' ';
	cout << '\n';
}
