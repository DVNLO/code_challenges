#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_all_strs(size_t const n) {
    vector<string> strs;
    strs.emplace_back(string());
    size_t j{0};
    for (size_t i{0}; i < n; ++i) {
        size_t const strs_sz{strs.size()};
        for (; j < strs_sz; ++j) {
            for(char c{ 'a' }; c <= 'z'; ++c)
            {
                strs.emplace_back(strs[j] + c);
            }
        }
    }
    return strs;
}

int main() {
    size_t constexpr n{5};
    fstream f("out.txt", ios::binary | ios_base::out);
    if(!f.is_open())
    {
	    cout << "file open failure\n";
	    return 0;
    }
    auto const strs{get_all_strs(n)};
    for(auto const & str : strs)
    {
        f << str << '\n';
    }
}
