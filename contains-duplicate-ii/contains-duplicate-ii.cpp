class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,pair<bool,int>> m;
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            auto isPresent = (m.find(nums[i]) != m.end());
            if(!isPresent)
            {
                m[nums[i]] = make_pair(true,i);
            }else{
                if(i - m[nums[i]].second <= k)
                {
                    return true;
                }else{
                    m[nums[i]].second = i;
                }
            }
        }
        
        return false;
    }
};