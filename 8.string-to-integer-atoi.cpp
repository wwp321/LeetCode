/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
    int MAX = 0x7FFFFFFF ;
    int MIN = 0x80000000 ;
    int MAX_FLAG = MAX / 10;
public:
    int myAtoi(string str) {
        bool negative = false, overflow = false, hasNum = false;
        char index = 0, val = 0, flagNum = 0 ;
        int result = 0;

        for(;index < str.size();index++)
        {
            val = str.at(index);
            if(val >= '0' && val <= '9')
            {
                hasNum = true;
                if(result > ((MAX - (val - '0')) / 10))
                {
                    overflow = true;
                    break;
                }
                result = (result << 3) + (result << 1) + (val - '0'); 
            }
            else if(val == ' ')
            {
                if(hasNum || flagNum > 0)
                {
                    break;
                    result = 0;
                    negative = false;
                }
                else
                continue;
            }
            else if(val == '-' || val == '+' )
            {
                flagNum ++;
                if(flagNum < 2 && !hasNum)
                negative = val == '-'?true:false;
                if(flagNum > 1 && !hasNum )
                {
                    result = 0;
                    negative = false;
                    break;
                }
                if(hasNum){
                    break;
                }
            }
            else
            {
                break;
            }
            
        }

        if(overflow)
        {
            if(negative){
                return MIN;
            }else{
                return MAX;
            }
        }else{
            return negative?0-result:result;
        }
    }
};
// @lc code=end

