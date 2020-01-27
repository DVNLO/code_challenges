// After submitting my solution below I was reviewing work
// others had submitted, and I was impressed by some of 
// the other solutions people submitted. One person in 
// particular leveraged the largest to smallest structure
// of ruman numerials to either ADD or SUBTRACT. Addition
// of the discovered numeral would occur if the discovered
// character was less than or equal to the previousily
// found character. Otherwise, it would subtract the found
// numerials value from the accumulating sum. Very interesting.
// I chose to implement this solution on my second attempt.
// Spending the extra time on this felt like a waste of time.
// Use a map, and rembember this strategy for furture 
// possibilities.

class Solution {
public:
    /* Returns the integer value of a sequence of upper case
     * roman numeral characters. The code is cryptic, and would
     * be difficult to maintain, imo. However, it is fast. 
     */
    int romanToInt(string s) 
    {
        size_t const S_SIZE{ s.size() };
        int ret_val{ 0 };
        int tmp;
        for(size_t i{ 0U }; i < S_SIZE; ++i)
        {
            switch(s[i])
            {
                case 'I':
                    {
                        tmp = 1;    // I == 1
                        if(i + 1 < S_SIZE)
                        {
                            ++i;
                            if(s[i] == 'V')
                                tmp += 3;    // IV == 4
                            else if(s[i] == 'X')
                                tmp += 8;    // IX == 9
                            else
                                --i;
                        }
                    }
                    break;
                case 'V':
                    tmp = 5;    // V == 5
                    break;
                case 'X':
                    {
                        tmp = 10;   // X == 10
                        if(i + 1 < S_SIZE)
                        {
                            ++i;
                            if(s[i] == 'L')
                                tmp += 30;    // IV == 40
                            else if(s[i] == 'C')
                                tmp += 80;    // IX == 90
                            else
                                --i;
                        }
                    }
                    break;
                case 'L':
                    tmp = 50; // L == 50
                    break;
                case 'C':
                    {
                        tmp = 100;   // C == 100
                        if(i + 1 < S_SIZE)
                        {
                            ++i;
                            if(s[i] == 'D')
                                tmp += 300;    // CD == 400
                            else if(s[i] == 'M')
                                tmp += 800;    // CM == 900
                            else
                                --i;
                        }
                    }
                    break;
                case 'D':
                    tmp = 500;
                    break;
                case 'M':
                    tmp = 1000;
                    break;
		default:
		    // error handling
		    break;
            }
            ret_val += tmp;
        }
        return ret_val;
    }
};
