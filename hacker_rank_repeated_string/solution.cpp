// The following was an excellent problem utilizeing the 
// division algorithm. Admittedly I struggled with this solution
// initially. I found it easy to implement an iterative solution,
// at first with modulo, secondarily with wrapping the index around
// (I left some of my code from this attempt below). However, in
// my final attempt I was able to recognize that the amounts could
// be easily computed with modulo arithemetic and counting the 
// number of wraps occured and multiplying the times we wrapped
// by the a count. We can then only iterate through the remainder
// quantity to determine the final piece of the sum. // end of poor english, lol. 

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) 
{
    long a_count = 0;
    size_t const size{ s.size() };
    long wraps = n / size;
    size_t remainder = n % size;
    for(size_t i{ 0 }; i < size; ++i)
    {
        if(s[i] == 'a')
            ++a_count;
    }
    long remainder_count = 0;
    for(size_t i{ 0 }; i < remainder; ++i)
    {
        if(s[i] == 'a')
            ++remainder_count;
    }
    return (a_count * wraps) + remainder_count;

    /*
    long a_count = 0;
    const size_t bound_idx{ s.size() - 1};
    for(long i{ 0 }; n > 0; --n)
    {
        if(s[i] == 'a')
            ++a_count;
        if(i == bound_idx)
            i = 0;
        else
            ++i;
    }*/
    return a_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

