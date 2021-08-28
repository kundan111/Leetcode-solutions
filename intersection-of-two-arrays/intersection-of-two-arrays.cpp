class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vec;
        vec.resize(1001,0);
        for(int v1: nums1)
        {
            vec[v1]++;
        }
        set<int> s;
        for(int v2: nums2)
        {
            if(vec[v2] > 0)
            {
                s.insert(v2);
                vec[v2]--;
            }
        }
        
        vector<int> res(s.begin(),s.end());
        
        
        return res;
        
    }
};