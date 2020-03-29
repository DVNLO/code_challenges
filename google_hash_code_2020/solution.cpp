#include <bits/stdc++.h>
using namespace std;

vector<int> scores;

struct library
{
    int book_count;
    int signup_delay;
    int throughput;
    vector<int> books;
};

bool is_greater_score(int const lhs, int const rhs)
{
    return scores[lhs] > scores[rhs];
}

void print(library const & lib)
{
    cout << lib.book_count << ' ' 
         << lib.signup_delay << ' ' 
         << lib.throughput << '\n';
    for(auto const book : lib.books)
        cout << book << ' ';
    cout << '\n';
}

void print(vector<library> const & libraries)
{
    for(auto const & library : libraries)
    {
        print(library);
        cout << '\n';
    }    
}

pair<int, unordered_set<int>> 
get_score_and_books(library const & lib,
                    vector<bool> const & is_book_scanned,
                    int const BEGIN_DAY,
                    int const END_DAY)
{
    int cur_day{ BEGIN_DAY };
    int i{ 0 };
    int const BOOK_COUNT{ static_cast<int>(lib.books.size()) };
    unordered_set<int> books_contributing_to_score;
    int score{ 0 };
    while(cur_day < END_DAY 
          && i < BOOK_COUNT)
    {
        for(int t{ 0 }; 
            t < lib.throughput && i < BOOK_COUNT; 
            ++t)
        {
            if(!is_book_scanned[lib.books[i]] 
               && !books_contributing_to_score.count(lib.books[i]))
            {
                books_contributing_to_score.insert(lib.books[i]);
                score += lib.books[i];
            }
        ++i;
        }
        ++cur_day;
    }
    return { score, books_contributing_to_score };
}

pair<int, unordered_set<int>>
select_library_to_register(vector<library> const & libraries, 
                           vector<bool> const & is_library_signed,
                           vector<bool> const & is_book_scanned, 
                           int const BEGIN_DAY,
                           int const END_DAY,
                           int const LIB_COUNT)
{
    int lib_with_max_score{ 0 };
    int max_score{ 0 };
    unordered_set<int> max_books;
    pair<int, unordered_set<int>> score_and_books;
    for(int i{ 0 }; i < LIB_COUNT; ++i)
    {
        if(is_library_signed[i])
            continue;
        score_and_books = get_score_and_books(libraries[i], 
                                              is_book_scanned,
                                              BEGIN_DAY + libraries[i].signup_delay,
                                              END_DAY);
        if(score_and_books.first > max_score)
        {
            lib_with_max_score = i;
            max_score = score_and_books.first;
            max_books = score_and_books.second;
        }
    }
    return { lib_with_max_score, max_books };
}

void scan_books(int const lib, 
                unordered_set<int> books_to_scan,
                vector<vector<int>> & library_books_scanned,
                vector<bool> & is_book_scanned)
{
    for(auto const book_to_scan : books_to_scan)
    {
        library_books_scanned[lib].emplace_back(book_to_scan);
        is_book_scanned[book_to_scan] = true;
    }
}

int main()
{
    int BOOK_COUNT;
    int LIB_COUNT;
    int DAY_COUNT;
    cin >> BOOK_COUNT >> LIB_COUNT >> DAY_COUNT;
    scores.resize(BOOK_COUNT);
    for(int i{ 0 }; i < BOOK_COUNT; ++i)
        cin >> scores[i];
    int book_count;
    int signup_delay;
    int throughput;
    vector<library> libraries(LIB_COUNT);
    for(int i{ 0 }; i < LIB_COUNT; ++i)
    {
        cin >> book_count >> signup_delay >> throughput;
        vector<int> books(book_count);
        for(int j{ 0 }; j < book_count; ++j)
            cin >> books[j];
        sort(books.begin(), books.end(), is_greater_score);
        libraries[i] = { book_count, signup_delay, throughput, books };
    }
///////////////////////////////////////////////////////////////////////////////
    vector<int> libraries_signed;
    vector<vector<int>> library_books_scanned(LIB_COUNT, vector<int>());
    vector<bool> is_library_signed(LIB_COUNT, false);
    vector<bool> is_book_scanned(BOOK_COUNT, false);
    int cur_day{ 0 };
    pair<int, unordered_set<int>> lib_and_books_to_scan;
    while(cur_day < DAY_COUNT)
    {
       lib_and_books_to_scan = select_library_to_register(libraries, 
                                                          is_library_signed, 
                                                          is_book_scanned,
                                                          cur_day, 
                                                          DAY_COUNT,
                                                          LIB_COUNT);
        if(lib_and_books_to_scan.second.empty())
            break;
        scan_books(lib_and_books_to_scan.first, 
                   lib_and_books_to_scan.second, 
                   library_books_scanned,
                   is_book_scanned);
        libraries_signed.emplace_back(lib_and_books_to_scan.first);
        is_library_signed[lib_and_books_to_scan.first] = true;
        cur_day += libraries[lib_and_books_to_scan.first].signup_delay;
    }
///////////////////////////////////////////////////////////////////////////////
    cout << libraries_signed.size() << '\n';
    for(auto const library_signed : libraries_signed)
    {
        cout << library_signed << ' ' 
             << library_books_scanned[library_signed].size() << '\n';
    for(auto const book : library_books_scanned[library_signed])
            cout << book << ' ';
    cout << '\n';
    }
    cout << endl;
}
