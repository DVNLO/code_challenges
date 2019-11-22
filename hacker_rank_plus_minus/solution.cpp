/* The following is a solution to hackerrank's prompt 
 * plus minus. The original prompt can be found here:
 * https://www.hackerrank.com/challenges/plus-minus/problem?h_r%5B%5D=next-challenge&h_r%5B%5D=next-challenge&h_r%5B%5D=next-challenge&h_v%5B%5D=zen&h_v%5B%5D=zen&h_v%5B%5D=zen&isFullScreen=true
 */
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) 
{
    vector<int>::size_type const SIZE{ arr.size() };
    vector<int>::size_type positive_val_count{ 0 };
    vector<int>::size_type negative_val_count{ 0 };
    vector<int>::size_type zero_val_count{ 0 };
    for(vector<int>::size_type i{ 0 }; 
        i < SIZE;
        ++i)
    {
        if(arr[i] > 0)
            ++positive_val_count;
        else if(arr[i] < 0)
            ++negative_val_count;
        else
            ++zero_val_count;
    }
    double const positive_val_frequency{ static_cast<double>(positive_val_count) / SIZE };
    double const negative_val_frequency{ static_cast<double>(negative_val_count) / SIZE };
    double const zero_val_frequency{ static_cast<double>(zero_val_count) / SIZE };
    printf("%.6f\n%.6f\n%.6f\n", positive_val_frequency,
                                 negative_val_frequency,
                                 zero_val_frequency);
}

int main()
{
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

    plusMinus(arr);

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

