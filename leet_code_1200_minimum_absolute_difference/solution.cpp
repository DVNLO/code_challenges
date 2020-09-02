class Solution {
public:
    vector<vector<int>> 
    minimumAbsDifference(vector<int>& arr) 
    {
        vector<vector<int>> ret;
        sort(begin(arr), end(arr));
        size_t const SIZE_ARR{ arr.size() };
        int diff;
        vector<int> min_pair(2);
        int min_diff = INT_MAX;
        for(size_t i{ 1U }; i < SIZE_ARR; ++i)
        {
            diff = arr[i] - arr[i - 1];
            if(diff < min_diff)
            {
                min_diff = diff;
            }
        }
        for(size_t i{ 1U }; i < SIZE_ARR; ++i)
        {
            diff = arr[i] - arr[i - 1];
            if(diff == min_diff)
            {                
                ret.push_back({arr[i - 1], arr[i]});
            }
        }
        return ret;
    }
};
