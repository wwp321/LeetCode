/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int MAX = 0x7FFFFFFF;
        int MIN = 0x80000000;
        bool active = x > 0;

        if (x > MIN && x < MAX)
        {
            x = active ? x : - x;
            while (x > 0)
            {
                if (result > MAX / 10) {
                    return 0;
                }
                result = result * 10 + (x % 10);
                x = x / 10;
            }
        }
        return active ? result : -result;
    }
};
// @lc code=end

