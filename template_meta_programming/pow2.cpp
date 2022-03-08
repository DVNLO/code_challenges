#include <iostream> 
using namespace std; 

template<unsigned int n>
struct pow2
{
    enum { val = 2 * pow2<n - 1>::val };
};

template<>
struct pow2<0>
{
    enum{ val = 1 };
};
  
int main() 
{ 
    cout << pow2<8>::val << endl; 
    return 0; 
} 
