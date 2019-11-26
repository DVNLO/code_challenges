#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) 
{
    // sorting the queries before you get them will enable more effective chaceing!
    vector<long long> vals(n, 0);
    size_t const A_IDX{ 0 };
    size_t const B_IDX{ 1 };
    size_t const K_IDX{ 2 };
    long long max{ numeric_limits<long long>::min() };
    for(auto const query : queries)
    {
        for(int j{ query[A_IDX] - 1 }; 
            j < query[B_IDX]; 
            ++j)
        {
            vals[j] += query[K_IDX];
            max = std::max(max, vals[j]);
        }
    }
    return max;
}

// unfortunately, sorting our queries does not optimize the solution. In fact, 
// sorting will have O(nlog(n)) overhead just to perform the sorting. Therefore,
// we need an alternative algorithm. I read in the discussion section, rather
// than storing the absolute values, we could store the magnitudes with an 
// encoding scheme where for a query q composed of a b c we set the original 
// val[a] = val[a] + k and set val[b] = val[b] - k using this type of encoding 
// we can form a superposition of the values between all the pairs of points in 
// the queries, thus it's like we're storing the slopes at any single point
// and we can determine the absolute value at a single point by accumulating
// all the changes from left to right. The maximum value we obtain is then
// the maximum value our accumulation achieves. That's a fundamentally intriguing
// solution. SLOPE ENCODING! STORE THE CHANGE AT a and b within the interval. We are
// changed by a and when we leave the interval we are changed by slope b.
// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) 
{
    static size_t const A_IDX{ 0 };
    static size_t const B_IDX{ 1 };
    static size_t const K_IDX{ 2 };
    vector<long long> vals(n, 0);
    for(auto const query : queries)
    {
        vals[query[A_IDX] - 1] += query[K_IDX];	// step UP!
        if(query[B_IDX] < n)
        {
            vals[query[B_IDX]] -= query[K_IDX];    // step DOWN!
        }
    }
    long long max{ numeric_limits<long long>::min() };
    long long accumulator{ 0 };
    for(auto const val : vals)
    {
        accumulator += val;
        max = std::max(max, accumulator);
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

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
