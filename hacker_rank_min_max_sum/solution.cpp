// https://www.hackerrank.com/challenges/mini-max-sum/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) 
{
    if(arr.empty())
        return;
    long long sum{ arr[0] };
    int min_val{ arr[0] };
    int max_val{ arr[0] };
    size_t const SIZE{ arr.size() };
    for(size_t i{ 1 }; 
        i < SIZE; 
        ++i)
    {
        min_val = std::min(arr[i], min_val);
        max_val = std::max(arr[i], max_val);
        sum += arr[i];
    }
    printf("%lld %lld", 
            sum - max_val, 
            sum - min_val);

}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

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

