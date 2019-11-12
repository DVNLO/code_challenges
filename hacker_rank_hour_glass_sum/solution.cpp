#include <bits/stdc++.h>

using namespace std;

int hour_glass_val(vector<vector<int>> const & arr, 
                    size_t const i, 
                    size_t const j)
{
    size_t const LEFT_COLUMN{ j - 1 };
    size_t const RIGHT_COLUMN{ j + 1 };
    size_t const TOP_ROW{ i - 1 };
    size_t const BOT_ROW{ i + 1 };
    int sum{ 0 };
    for(size_t i{ LEFT_COLUMN }; i <= RIGHT_COLUMN; ++i)
        sum += arr[TOP_ROW][i];
    for(size_t i{ LEFT_COLUMN }; i <= RIGHT_COLUMN; ++i)
        sum += arr[BOT_ROW][i];
    return sum += arr[i][j];
}

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    size_t const row_count{ arr.size() };
    if(!row_count)
        return 0;
    size_t const row_bound{ row_count - 1 };
    size_t const column_count{ arr[0].size() };
    size_t const column_bound{ column_count - 1 };
    int max_hour_glass_sum{ numeric_limits<int>::min() };
    for(size_t i{ 1 }; i < row_bound; ++i)
    {
        for(size_t j{ 1 }; j < column_bound; ++j)
        {
            max_hour_glass_sum = max(max_hour_glass_sum, 
                                        hour_glass_val(arr, i, j));
        }
    }
    return max_hour_glass_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

