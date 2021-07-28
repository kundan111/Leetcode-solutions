class Solution {
public:
    int res = 0;
    int minOperations(vector<int>& nums) {
       ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
       int cur = nums[0] ;
       int sz = nums.size();
        
       for(int i = 1; i < sz; i++)
       {
           if(nums[i] <= cur)
           {
               res += (cur+1 - nums[i]);
               
               cur = cur+1;
           }else{
               cur = nums[i];
           }
       }
        return res;
    }
};