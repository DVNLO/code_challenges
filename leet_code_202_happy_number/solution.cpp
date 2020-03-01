// This was an odd problem. The solution is math heavy, and while I think
// an analysis of the proof for this problem will be helpful, it's 
// relatively obvious that if the possible number of values are bounded
// and two things are traveling through those values at different rates, 
// they will eventually collide. The intuition here is the same as the 
// circular list detection algorithm. This is listed as a "top" interview
// question but sincerely, I think this falls into that "know one special fact"
// category of questions which aren't great interview questions. 

class Solution {
public:
    
    int sum_digit_squares(int val)
    {
        int sum{ 0 };
        int digit;
        while(val)
        {
            digit = val % 10;
            sum += digit * digit;
            val /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) 
    {
        int slow{ n };
        int fast{ n };
        do
        {
            slow = sum_digit_squares(slow);
            fast = sum_digit_squares(sum_digit_squares(fast));
        } while(slow != fast);
        return slow == 1;
    }
};
