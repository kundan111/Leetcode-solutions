class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sz = nums.size();
        unordered_map<int,int>m;
        int l = 0;
        int r = -1;
        
        int res = -1;
        int curWindow = 0;
        while( r < sz)
        {
            
            
            while(r + 1 < sz && m.find(nums[r+1]) == m.end())
            {
                // cout << "yo1" << endl;
                r++;
                curWindow += nums[r];
                m[nums[r]]++;
            }
            
            res = max(res,curWindow);
            
            
            
            if(r == sz-1)
            {
                return res;
            }
            
            while(l < sz && nums[l] != nums[r+1])
            {
                // cout << "yo2" << endl;
                m[nums[l]]--;
                curWindow -= nums[l];
                if(m[nums[l]] == 0)
                {
                    m.erase(nums[l]);
                }
                l++;
            }
            
            if(l < sz && nums[l] == nums[r+1])
            {
                // cout << "yo3" << endl;
                 m[nums[l]]--;
                curWindow -= nums[l];
                if(m[nums[l]] == 0)
                {
                    // cout << "yo4" << endl;
                    
                    m.erase(nums[l]);
                }
                // cout << "m.size(): " << m.size() << endl;
                l++;
            }
            
            
            // cout << "l: " << l << endl << "r: " << r << endl << endl;
            
            
        }
        
        
        
        return res;
        
        
        
        
        
    }
};