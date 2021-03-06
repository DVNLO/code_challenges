/*
The following is a solution to prompt 682. Baseball Game from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/baseball-game/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
	int calPoints(std::vector<std::string>& ops) {
		bool* roundValidity = new bool[ops.size()] { false };
		int sum = 0;
		for (int i = 0; i < ops.size(); i++)
		{
			if (isdigit(ops[i][0]) || (ops[i][0] == '-' && isdigit(ops[i][1]))) {
				sum += stoi(ops[i]);
				roundValidity[i] = true;
			}
			else if (ops[i] == "C") {    //the last valid round's points you get were invalid and should be removed.
				int d = i;
				while (d > 0 && !roundValidity[d])
					d--;
				sum -= stoi(ops[d]);
				roundValidity[d] = false;
				roundValidity[i] = false;
			}
			else if (ops[i] == "D") {    //the points you get in this round are the doubled data of the last valid round's points.
				int d = i;
				while (d > 0 && !roundValidity[d])
					d--;
				int dvalue = 2 * stoi(ops[d]);
				sum += dvalue;
				ops[i] = std::to_string(dvalue);
				roundValidity[i] = true;
			}
			else {  //+ the points you get in this round are the sum of the last two valid round's points.
				int first = i;
				while (first > 1 && !roundValidity[first])
					first--;
				int second = first - 1;
				while (second > 0 && !roundValidity[second])
					second--;
				int dvalue = stoi(ops[first]) + stoi(ops[second]);
				sum += dvalue;
				ops[i] = std::to_string(dvalue);
				roundValidity[i] = true;
			}
			/*
			cout << i << " " << sum << endl;
			for(string s : ops)
			cout << s << " ";
			cout << endl;
			*/
		}
		delete[] roundValidity;
		return sum;
	}
};

int main()
{
	Solution prompt;
	std::vector<std::string> input = { "5","2","C","D","+" };
	std::cout << prompt.calPoints(input) << std::endl;
    return 0;
}

