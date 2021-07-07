class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            int cur = nums[i];
            int temp = 0;
            for(int j = 0; j < n; j++)
            {
                if(j != i && nums[j] < cur)
                    temp++;
            }
            res.push_back(temp);
        }
        
        return res;
    }
};