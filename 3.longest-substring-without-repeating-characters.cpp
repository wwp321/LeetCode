/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t CharArray[128] = {0};
        int arrsize = sizeof(size_t) << 7;
        int maxSize = 0, size = 0;
        size_t ssize = s.size(), index = 0;
        while(index < ssize)
        {
            char c = s.at(index);
            if(CharArray[c] == 0)
            {
                CharArray[c]= index + 1;
                size++;
                index++;
            }
            else
            {
                if(size > maxSize){
                    maxSize = size;
                }
                size=0;
                index=CharArray[c];
                memset(CharArray,0,arrsize);
            }
            
        }
        return maxSize>size?maxSize:size;
    }
};
// @lc code=end

