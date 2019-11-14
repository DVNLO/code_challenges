#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps_n2(vector<int> arr) 
{
    int const size{ arr.size() };
    if(size <= 2)
    {
        return 0;
    }
    int swap_count{ 0 };
    for(int i{ 0 }; i < size; ++i)
    {
        if(arr[i] == i + 1)
        {
            continue;
        }
        else
        {
            int j{ i + 1};
            for(; j < size; ++j)
            {
                if(arr[j] == i + 1)
                    break;
            }
            swap(arr[i], arr[j]);
            ++swap_count;
        }
    }
    return swap_count;
}

// an alternative way without O(N^2)
// This is a very exceptional solution to this problemm, in my humble opinnion.
// With this algorithm, we know we know which place the value at the front of the 
// array needs to be because it's value dictates that. So we can move that 
// value to it's target location, and bring whatever's there to the front
// and continue swapping until we find the correct value for the front. Once
// we have the correct values, we can iterate through the array checking that we
// have the correct values at each ith position. In the worst case we make n-1
// swaps where n is the length of the array, and then iterate through it so 
// two passes which is a linear bound on operations performed.
int minimumSwaps_linear(vector<int> arr) 
{    
    int const size{ arr.size() };
    if(size <= 1)
    {
        return 0;
    }
    int swap_count{ 0 };
    for(int i{ 0 }; i < size;)
    {
        if(arr[i] == i + 1)
        {
            ++i;
        }
        else
        {
            swap(arr[i], arr[arr[i] - 1]);
            swap_count++;
        }
    }
    return swap_count;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

