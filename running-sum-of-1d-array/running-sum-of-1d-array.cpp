class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> retVector;
        int i = 0;
        int sz = nums.size();
        int last_sum = 0;
        while(i < sz)
        {
            int ele = nums[i];
            retVector.push_back(ele + last_sum);
            last_sum = ele + last_sum;
            i++;
        }
        
        return retVector;
    }
};