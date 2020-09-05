class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int index = 0; index < nums.size() - 1 ;index++)
        {
            for(int index1 = index + 1; index1 < nums.size();index1++)
            {
                if(nums[index] + nums[index1] == target)
                {
                    result.push_back(index);
                    result.push_back(index1);
                    return result;
                }
            }
        }
        return result;
    }
};