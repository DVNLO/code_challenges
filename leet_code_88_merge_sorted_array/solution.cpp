// The following is my accepted solution to leetcode's prompt:
// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, 
               vector<int>& nums2, int n) 
    {
        vector<int>::reverse_iterator target{ nums1.rbegin() };
        vector<int>::reverse_iterator one{ nums1.rbegin() + n };
        vector<int>::reverse_iterator two{ nums2.rbegin() };
        while(one != nums1.rend()
                && two != nums2.rend())
        {
            if(*one >= *two)
            {
                *target = *one;
                ++one;
            }
            else
            {
                *target = *two;
                ++two;
            }
            ++target;
        }
        while(one != nums1.rend())	// copy remainder
        {
            *target = *one;
            ++one;
            ++target;
        }
        while(two != nums2.rend())	// copy remainder
        {
            *target = *two;
            ++two;
            ++target;
        }
    }
};
