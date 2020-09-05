/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int overflow = 0;
       int l1v=0,l2v=0;
       ListNode* resultHead = new ListNode();
        ListNode* result = resultHead;
        while(1)
        {
            l1v=getVal(l1);
            l2v=getVal(l2);

            if(l1 != nullptr || l2 != nullptr || overflow != 0)
            {
                result->val = l1v + l2v + overflow;
                if(result->val >= 10)
                {
                    result->val -= 10;
                    overflow = 1;
                }
                else
                {
                    overflow = 0;
                }
                
                l1 = getNext(l1);
                l2 = getNext(l2);
                if(l1 != nullptr || l2 != nullptr || overflow != 0)
                {
                    result->next = new ListNode();
                    result = result->next;
                }
                
            }else
            {
                break;
            }
            
        }
       return resultHead;
    }
private:
    int getVal(ListNode* l1)
    {
        if(l1==nullptr)
        {
            return 0;
        }
        else
        {
            return l1->val;
        }
    }
    ListNode* getNext(ListNode* l1)
    {
        if(l1 != nullptr)
        {
            return l1->next;
        }
        return nullptr;
    }
};
// @lc code=end

