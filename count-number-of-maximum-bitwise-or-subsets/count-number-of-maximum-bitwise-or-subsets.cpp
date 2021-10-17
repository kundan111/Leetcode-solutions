class Solution {
private:
    unordered_map<long long int, int> m;
public:
    int countMaxOrSubsets(vector<int>& nums) {
        long long int maxOR = -1;
        int maxCount = 0;
        // generate all sussets and take their or
        int sz = nums.size();
        for(int i = 1; i < pow(2,sz); i++)
        {
            long long int thisOR = 0;
            for(int bit = 0; bit < sz; bit++)
            {
                
                if(i & (1 << bit))
                {
                    thisOR |= nums[sz - bit -1];
                }
            }
            
            // cout << "thisOR: " << thisOR << endl;
            
            m[thisOR]++;
            if(thisOR >= maxOR)
            {
                maxOR = thisOR;
                maxCount = m[thisOR];
            }
        }
        // cout << "maxOR: " << maxOR << endl;
        
        return maxCount;
    }
};