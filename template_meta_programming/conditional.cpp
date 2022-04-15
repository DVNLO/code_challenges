#include <bits/stdc++.h>
using namespace std;

// identity type query
template<typename T>
struct type_is
{
    using type = T;
};

template<bool, typename T, typename F>
struct IF 
{
};

// partial specialization of IF when true
template<typename T, typename F>
struct IF<true, T, F> : type_is<T>
{
};

// partial specialization of IF when false
template<typename T, typename F>
struct IF<false, T, F> : type_is<F>
{
};

int main()
{
    // Define VAL from the command line by passing -D flag to g++ like
    // g++ -D VAL=1 ./conditional.cpp ;
    // to modify the behavior of the program and configure the type 
    // for the variable i.

    IF<(VAL > 0), int, char>::type i;
    assert(sizeof(i) == sizeof(int));
    cout << "sizeof(i) == " << sizeof(i) << '\n'
         << "sizeof(int) == " << sizeof(int) << '\n'
         << "sizeof(char) == " << sizeof(char) << '\n'
         << "VAL == " << VAL << std::endl;
}

