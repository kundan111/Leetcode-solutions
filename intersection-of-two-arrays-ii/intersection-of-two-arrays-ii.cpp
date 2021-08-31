class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(int val: nums1)
        {
            m[val]++;
        }
        
        vector<int>res;
        for(int val: nums2)
        {
            if(m[val])
            {
                m[val]--;
                res.push_back(val);
                if(m[val] == 0)
                {
                    m.erase(val);
                }
            }
        }
        
        
        return res;
    }
};