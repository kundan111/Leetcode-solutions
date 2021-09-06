class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        
        int sz = nums.size();
        int res = -1;
        while(end < sz)
        {
            if(nums[end] == 0)
            {
                k--;
            }
            while(k < 0)
            {
                if(nums[start] == 0)
                {
                    k++;
                }
                start++;
            }
            end++;
            
            res = max(res,end-start);
        }
        
        return res;
    }
};