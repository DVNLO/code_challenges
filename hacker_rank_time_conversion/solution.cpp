// I didn't like this problem very much, but I made a solid
// effort to amortize the cost of computing the conversion.
// Not sure if it's more optimal than all the intermediary 
// string to int conversions, but it works. 
// https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) 
{
    static unordered_map<string, string> const conversion_map{ 
                                                    { "12AM", "00" },
                                                    { "01AM", "01" },
                                                    { "02AM", "02" },
                                                    { "03AM", "03" },
                                                    { "04AM", "04" },
                                                    { "05AM", "05" },
                                                    { "06AM", "06" },
                                                    { "07AM", "07" },
                                                    { "08AM", "08" },
                                                    { "09AM", "09" },
                                                    { "10AM", "10" },
                                                    { "11AM", "11" },
                                                    { "12PM", "12" },
                                                    { "01PM", "13" },
                                                    { "02PM", "14" },
                                                    { "03PM", "15" },
                                                    { "04PM", "16" },
                                                    { "05PM", "17" },
                                                    { "06PM", "18" },
                                                    { "07PM", "19" },
                                                    { "08PM", "20" },
                                                    { "09PM", "21" },
                                                    { "10PM", "22" },
                                                    { "11PM", "23" } };
    static size_t constexpr HOUR_TENS_DIGIT_IDX{ 0 };
    static size_t constexpr HOUR_ONES_DIGIT_IDX{ 1 };
    static size_t constexpr HOUR_DIGIT_COUNT{ 2 };
    string const hour{ s.substr(HOUR_TENS_DIGIT_IDX, HOUR_DIGIT_COUNT) };
    static size_t constexpr SUFFIX_IDX{ 8 };
    static size_t constexpr SUFFIX_LENGTH{ 2 };
    string const suffix{ s.substr(SUFFIX_IDX, SUFFIX_LENGTH) };
    auto const got{ conversion_map.find(hour + suffix) };	// can assume this is successful by problem statement
    s[HOUR_TENS_DIGIT_IDX] = got->second[HOUR_TENS_DIGIT_IDX];
    s[HOUR_ONES_DIGIT_IDX] = got->second[HOUR_ONES_DIGIT_IDX];
    s.erase(SUFFIX_IDX, SUFFIX_LENGTH);
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

