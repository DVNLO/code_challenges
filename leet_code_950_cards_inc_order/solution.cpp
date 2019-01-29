#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        const unsigned size = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> ints;
        ints.push(deck[size - 1]);
        for(int i = size - 2; i >= 0; --i)
        {
            int front = ints.front();
            ints.pop();
            ints.push(front);
            ints.push(deck[i]);
        }
        vector<int> res(size);
        for(int j = size - 1; j >= 0; --j)
        {
            res[j] = ints.front();
            ints.pop();
        }
        return res;
    }
};

int main()
{
	Solution prompt;
	const unsigned size = 7;
	vector<int> A = {17, 13, 11, 2, 3, 5, 7};
	vector<int> B = prompt.deckRevealedIncreasing(A);
	for(unsigned i = 0; i < size; ++i)
		cout << B[i] << ' ';
	cout << '\n';
}	
