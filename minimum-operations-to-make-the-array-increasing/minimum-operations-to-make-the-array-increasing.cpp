class Solution {
public:
    int res = 0;
    int minOperations(vector<int>& nums) {
       
       int cur = nums[0] ;
       int sz = nums.size();
        
       for(int i = 1; i < sz; i++)
       {
           if(nums[i] <= cur)
           {
               res += (cur+1 - nums[i]);
               nums[i] = cur+1;
               cur = nums[i];
           }else{
               cur = nums[i];
           }
       }
        return res;
    }
};