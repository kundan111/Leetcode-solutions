class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        return sz*(sz+1)/2 - sum;
    }
};