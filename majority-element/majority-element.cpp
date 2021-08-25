class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz = nums.size();
        int i = 0;
        int max_count = 0;
        int res = -1;
        while(i < sz)
        {
            int cur = nums[i];
            int count = 0;
            while(i < sz && nums[i] == cur)
            {
                count++;
                i++;
            }
            // cout << cur << " -> "  << count << endl;
            if(count > max_count)
            {
                max_count = count;
                res = cur;
            }
        }
        
        
        return res;
    }
};