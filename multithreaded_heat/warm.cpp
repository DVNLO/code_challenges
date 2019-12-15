#include <bits/stdc++.h>
using namespace std;

unsigned int ackermann(unsigned int m, unsigned int n) 
{
	if (m == 0) {
		return n + 1;
	}
	if (n == 0) {
		return ackermann(m - 1, 1);
	}
	return ackermann(m - 1, ackermann(m, n - 1));
}

void warm() 
{
    ackermann(1000, 1000);
}

int main() 
{
    thread child(warm);
    for(int i{ 0 }; i < 24; ++i)
    {
        thread a(warm);
        a.detach();
    }
    child.join();
}
