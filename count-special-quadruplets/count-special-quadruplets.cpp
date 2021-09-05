class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;
        for(int i = 0; i <= sz-4; i++)
        {
            for(int j = i +1 ; j <= sz-3; j++)
            {
                for(int k = j + 1 ; k <= sz - 2; k++)
                {
                    for(int l = k + 1; l <= sz-1; l++)
                    {
                        if(nums[i] + nums[j] + nums[k] == nums[l])
                        {
                            
                            res++;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};