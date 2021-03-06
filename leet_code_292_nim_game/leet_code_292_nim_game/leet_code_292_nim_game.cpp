
/*
The following is a solution to prompt 292. Nim Game from 
leetcode.com. The prompt can be found here:
https://leetcode.com/problems/nim-game/description/
The solution can be found here:
https://leetcode.com/articles/nim-game/
In this prompt, we assume our opponent "is clever"
and always takes perfect actions to make us loose. 
We will loose when there are 4 stones in the pile. 
We can win when there are 1, 2, or 3 stones in the pile.
By induction, we can win when there are 5, 6, 7 stones 
in the pile, but will loose when there are 8. Therefore,
we can only win when n % 4 != 0. Trivial program with interesting
thinking. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"

class Solution {
public:
	bool canWinNim(int n) {
		return n % 4;
	}
};


int main()
{
	Solution prompt;
	prompt.canWinNim(4);
    return 0;
}

