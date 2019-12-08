#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int step_count{ 0U };
	int i{ 5U };
	do{
		step_count += n / i;
		n = n % i;
		--i;
	} while(n);
	printf("%d \n", step_count);
}
