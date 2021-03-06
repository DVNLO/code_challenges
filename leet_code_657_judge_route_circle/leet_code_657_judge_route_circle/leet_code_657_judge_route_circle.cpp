/*
The following is a solution to prompt 657 "Judge Route Circle"
from leetcode.com. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
Date: 9 June 2018
*/
#include "stdafx.h"
#include <iostream>
#include <string>

/*
Determines if a circle (no net displacement) is traversed 
from a sequence of moves.
@param moves a sequence of move characters.
@return true when no net displacement has occured.
*/
bool judgeCircle(std::string moves) {
	int net_horizontal_displacement = 0;
	int net_vertical_displacement = 0;
	for (char move : moves)
	{
		switch (move)
		{
		case 'L':	//left
			net_horizontal_displacement--;
			break;
		case 'R':	//right
			net_horizontal_displacement++;
			break;
		case 'U':	//up
			net_vertical_displacement++;
			break;
		case 'D':	//down
			net_vertical_displacement--;
			break;
		}
	}
	return !(net_horizontal_displacement || net_vertical_displacement);
}

int main()
{
	if (judgeCircle("LLRRUUDD"))
	{
		std::cout << "Circle!" << std::endl;
	}
    return 0;
}

