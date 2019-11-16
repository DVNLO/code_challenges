#include <bits/stdc++.h>

using namespace std;

bool is_anagram(string const & lhs,
                string const & rhs)
{
    if(lhs.size() != rhs.size())
        return false;
    unsigned char_counts[static_cast<size_t>('z' - 'a' + 1)] = { 0 };
    for(auto const c : lhs)
    {
        ++char_counts[static_cast<size_t>(c - 'a')];
    }
    size_t idx;
    for(auto const c : rhs)
    {
        idx = static_cast<size_t>(c - 'a');
        if(char_counts[idx])
            --char_counts[idx];
        else
            return false;
    }
    return true;
}

// This was my first attempt at building substrs. For
// some reason this initially felt more natural. In 
// hindsight it seems odd that this was initially
// more natural, and I never did prove that this 
// did form all substrs. I think it does though. 
void build_substrs(string str,
                    queue<char> symbols, 
                    vector<string> & substrs)
{
    substrs.emplace_back(str);
    char c;
    while(!symbols.empty())
    {
        c = symbols.front();
        symbols.pop();
        build_substrs(str + c, 
                        symbols,
                        substrs);
    }
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) 
{
    typedef vector<string>::size_type vstr_size_t;
    vstr_size_t const s_size{ s.size() };
    vector<string> substrs;
    for(vstr_size_t j{ 0U }; j < s_size; ++j)
    {
        for(vstr_size_t k{ j }; k < s_size; ++k)
        {
            substrs.emplace_back(s.substr(j, k - j + 1));
        }
    }
    int anagram_count{ 0 };
    vstr_size_t const substrs_size{ substrs.size() };
    for(vstr_size_t i{ 0U }; i < substrs_size; ++i)
    {
        for(vstr_size_t j{ i + 1U }; j < substrs_size; ++j)
        {
            if(is_anagram(substrs[i], substrs[j]))
                ++anagram_count;
        }
    }
    return anagram_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

