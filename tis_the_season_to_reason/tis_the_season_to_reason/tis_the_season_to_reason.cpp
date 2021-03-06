#include "pch.h"
#include <iostream>
#include <set>

int main()
{
	std::set<double> S = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	std::set<double> D = S;
	std::set<double> C;
	for (auto s : S) {
		for (auto d : D) {
			double q = s / d;
			if (!C.count(q) && s + d <= 12) {
				std::cout << '(' << s << ',' << d << ") == " << q << '\n';
				C.insert(q);
			}
		}
	}
	std::cout << C.size() << '\n';
}
/*
(1,1) == 1
(1,2) == 0.5
(1,3) == 0.333333
(1,4) == 0.25
(1,5) == 0.2
(1,6) == 0.166667
(1,7) == 0.142857
(1,8) == 0.125
(1,9) == 0.111111
(1,10) == 0.1
(1,11) == 0.0909091
(2,1) == 2
(2,3) == 0.666667
(2,5) == 0.4
(2,7) == 0.285714
(2,9) == 0.222222
(3,1) == 3
(3,2) == 1.5
(3,4) == 0.75
(3,5) == 0.6
(3,7) == 0.428571
(3,8) == 0.375
(4,1) == 4
(4,3) == 1.33333
(4,5) == 0.8
(4,7) == 0.571429
(5,1) == 5
(5,2) == 2.5
(5,3) == 1.66667
(5,4) == 1.25
(5,6) == 0.833333
(5,7) == 0.714286
(6,1) == 6
(6,5) == 1.2
(7,1) == 7
(7,2) == 3.5
(7,3) == 2.33333
(7,4) == 1.75
(7,5) == 1.4
(8,1) == 8
(8,3) == 2.66667
(9,1) == 9
(9,2) == 4.5
(10,1) == 10
(11,1) == 11
45

C:\Users\dvyen\Source\Repos\code_challenges\tis_the_season_to_reason\Debug\tis_the_season_to_reason.exe (process 24276) exited with code 0.
Press any key to close this window . . .
NOTE: There are "45" that can be formed from the above, and 2 more (1,0) and (0,1) that are also possible, the total is 47
*/