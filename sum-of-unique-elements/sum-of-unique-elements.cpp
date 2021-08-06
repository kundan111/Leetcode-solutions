class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        vector<int>arr(101,0);
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            arr[nums[i]]++;
        }
        
        int res = 0;
        
        for(int i = 0; i < 101; i++)
        {
            
            if(arr[i] == 1)
            {
                
                res = res + i;
            }
        }
        
        return res;
    }
};