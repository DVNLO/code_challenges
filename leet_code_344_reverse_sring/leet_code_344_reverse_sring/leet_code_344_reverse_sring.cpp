/*
The following is a solution to prompt 344. Reverse String from leetcode.com.
Per the prompmt title, this program reverses an input string by swapping 
characters within an input string around the central character.
The leetcode prompt can be found here: https://leetcode.com/problems/reverse-string/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
Date: 30 June 2018
*/

#include "stdafx.h"
#include <string>
#include <iostream>



// Yet another implementation. This time keeping an ending index.
class Solution {
public:
    void reverseString(vector<char>& s)
    {
        size_t const S_SIZE{ s.size() };
        size_t const MID_IDX{ S_SIZE / 2 };
        char c;
        size_t j = S_SIZE - 1;
        for(size_t i{ 0 }; i < MID_IDX; ++i)
        {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            --j;
        }
    }
};

// Revisiting this problem years later, this is the code I wrote compared 
// to my original work. Very interesting. Subtle changes, but same overall
// idea. Better use of the right shift and data types.
class Solution {
public:
    void reverseString(vector<char>& s)
    {
        size_t const S_SIZE{ s.size() };
        size_t const S_MIDPOINT{ S_SIZE >> 1 }; // divide by 2 to find midpoint
        char tmp;
        for(size_t i{ 0 }; i < S_MIDPOINT; ++i)
        {
            tmp = s[i];
            s[i] = s[S_SIZE - i - 1];
            s[S_SIZE - i - 1] = tmp;
        }
    }
};


class Solution {
public:
	std::string reverseString(std::string s) {
		int final_index = s.length();
		for (int i = 0; i < final_index / 2; i++)
		{
			char front = s[i];
			char back = s[final_index - i - 1];
			s[final_index - i - 1] = front;
			s[i] = back;
		}
		return s;
	}
};

int main()
{
	Solution prompt;
	std::cout << prompt.reverseString("hello");
	int x;
	std::cin >> x;
    return 0;
}

