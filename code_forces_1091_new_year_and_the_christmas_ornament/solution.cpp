#include <bits/stdc++.h>
using namespace std;
int main()
{
	// alice wants 3 types of ornaments on her tree yellow, blue and red
	// have y yellow, b blue, and r red ornaments.
	// A tree is beautiful if:
	// 	count(b) == count(y) + 1
	// 	count(r) == count(b) + 1 // note the consecutive sequence.
	// alice wants to choose as many ornaments as possible
	// and the tree to be beautiful to bob.
	int y, b, r;
	cin >> y >> b >> r;
	y = min(b, min(y, r));
	while(y + 1 > b || y + 2 > r)
		--y;
	cout << 3 * y + 3 << endl;
}
