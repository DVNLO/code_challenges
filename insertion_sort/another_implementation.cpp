#include <bits/stdc++.h>
using namespace std;

// Implemented based on pseudo code found in the book
// Introduction to Algorithms. As an analogy, the following
// can be visualized as sorting a hand of playing cards.
// We select a "key" card, the card we are looking to 
// position into the left sequence of sorted cards. Then,
// move all the sorted cards right until we find the place
// for the key card. The position of the key card in the 
// first index where the key is greater than or equal to
// the key. 
void insertion_sort(vector<int> & vals)
{
    if(vals.size() < 2)
        return;
    vector<int>::size_type const SIZE{ vals.size() };
    int key;
    vector<int>::size_type i;
    for(vector<int>::size_type j{ 1 }; 
        j < SIZE;
        ++j)
    {
        key = vals[j];
        i = j - 1;
        while(i >= 0 && vals[i] > key)
        {
            vals[i + 1] = vals[i];   // shift right
            --i;
        }
        vals[i + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i{ 0 }; i < n; ++i)
        cin >> vals[i];
    insertion_sort(vals);
    for(auto const val : vals)
        cout << val << ' ';
    cout << endl;
}
        
