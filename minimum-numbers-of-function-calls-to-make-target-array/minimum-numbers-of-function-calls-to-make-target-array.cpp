class Solution {
public:
    int minOperations(vector<int>& nums) {
       int res = 0;
       int oddCount = 0;
       int divisonOps = 1;
       for(auto val: nums)
       {
           int curDivisonOps = 0;
           while(val)
           {
               oddCount += (val & 1);
               curDivisonOps++;
               val >>= 1;
           }
           
           divisonOps = max(divisonOps,curDivisonOps);
           
           
       }
        
        return oddCount + divisonOps - 1;
    }
};