class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> m;
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            m[nums[i]]++;
        }
        
        if(m.size() == 1)
        {
            return 0;
        }
        
        int res = 0;
        auto itr = m.end();
        
        advance(itr,-1);
        int prev = 0;
        
        while(itr != m.begin())
        {
            res = res + (prev + itr->second);
            prev = prev + itr->second;
            itr--;
        }
        
        
        return res;
    }
};