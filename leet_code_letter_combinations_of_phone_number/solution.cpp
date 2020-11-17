class Solution {
public:
    
    vector<char>
    get_letters(char const digit)
    {
        switch(digit)
        {
            case '2':
                return { 'a', 'b', 'c' };
            case '3':
                return { 'd', 'e', 'f' };
            case '4':
                return { 'g', 'h', 'i' };
            case '5':
                return { 'j', 'k', 'l' };
            case '6':
                return { 'm', 'n', 'o' };
            case '7':
                return { 'p', 'q', 'r', 's' };
            case '8':
                return { 't', 'u', 'v' };
            case '9':
                return { 'w', 'x', 'y', 'z' };
            default:
                return { };
        }
    }
    
    void
    find_letter_combinations(string const s, string const digits, vector<string> & ret)
    // recursively discover all letter combination possible for the provided digits
    // store the provided combinations in the ret vector<string>
    {
        if(digits.empty())
        {
            // base case
            if(!s.empty())
            {
                // store non-empty strings
                ret.push_back(s);
            }
            return;
        }
        vector<char> letters = get_letters(digits[0]);
        for(char c : letters)
        {
            find_letter_combinations(s + c, digits.substr(1), ret);
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ret;
        find_letter_combinations("", digits, ret);
        return ret;
    }
};
