class Solution {
public:
    bool
    is_open_brace(char const c)
    {
        return c == '(' || c == '{' || c== '[';
    }
    
    bool
    is_close_brace(char const c)
    {
        return c == ')' || c == '}' || c== ']';
    }
    
    bool
    is_paren_match(char const open, char const close)
    {
        return (open == '(' && close == ')') 
               || (open == '{' && close == '}')
               || (open == '[' && close == ']');
    }
    
    bool 
    isValid(string s) 
    {
        std::stack<char> parens;
        bool is_valid{ true };
        for(char const c : s)
        {
            if(is_open_brace(c))
            {
                parens.push(c);
            }
            else if(is_close_brace(c))
            {
                if(parens.empty())
                {
                    is_valid = false;
                    break;
                }
                char top = parens.top();
                parens.pop();
                if(!is_paren_match(top, c))
                {
                    is_valid = false;
                    break;
                }
            }
            else
            {
                is_valid = false;   // unexpected character
                break;
            }
        }
        if(!parens.empty())
        {
            is_valid = false;
        }
        return is_valid;
    }
};
