class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        auto res = minmax_element(nums.begin(),nums.end());
        int l = 1;
        int r = *res.second;
        int ret ; 
        while(l <= r)
        {
            int cand = l + (r-l)/2;
            int res = result(nums,cand);
            
            // cout << "cand: " << cand << " res: " << res << endl;
            
            if(res <= t)
            {
                ret = cand;
                r = cand-1;
            }else{
                l = cand+1;
            }
            
        }
        
        return ret;
        
        
    }
    
    int result(vector<int>& nums,int cur)
    {
        int res = 0;
        for(int val: nums)
        {
            
            res += val%cur == 0 ? val/cur : val/cur + 1;
        }
        
        return res;
    }
};