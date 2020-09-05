/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int reverse = 0;
        int orix = x;
        int MAX = 0x7FFFFFFF;
        if (x > 0)
        {
            while (x > 0)
            {
                if(reverse > MAX / 10)
                {
                    break;
                }
                reverse = reverse * 10 + x % 10;
                x = x / 10;
            }
        }

        if (reverse == orix)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
