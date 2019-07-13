/* The following is a solution to leetcode prompt 1108 Defang Ip Address.
 * The original prompt can be found : https://leetcode.com/problems/defanging-an-ip-address/
 */


class Solution {
public:
    string defangIPaddr(string address) {
        string defang_addr;
        for(char const c : address)
        {
            if(c == '.')
            {
                defang_addr += "[.]";
            }
            else
            {
                defang_addr += c;
            }
        }
        return defang_addr;
    }
};
