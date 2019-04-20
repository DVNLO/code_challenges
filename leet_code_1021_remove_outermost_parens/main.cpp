/* The following is a solution prompt 1021 Remove outermost parenthesis
 * found here: https://leetcode.com/problems/remove-outermost-parentheses/
 */

class Solution {
public:
    string removeOuterParentheses(string S) {
        char const LEFT_PAREN = '(';
        char const RIGHT_PAREN = ')';
        if(S.size() <= 1)
        {
            return S;
        }
        size_t depth = 0;
        string res;
        for(char const & s : S)
        {
            if(s == LEFT_PAREN)
            {
                if(depth)
                {
                    res += s;
                }
                ++depth;
            }
            else if (s == RIGHT_PAREN)
            {
                --depth;
                if(depth)
                {
                    res += s;
                }
            }
        }
        return res;
    }
};
