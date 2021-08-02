class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,vector<int> > > m;
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            int val = nums[i];
            m[val].first++;
            m[val].second.push_back(i);
        }
        
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            int cur = i->first;
            int searchFor = target - cur;
            
            auto s = m.find(searchFor);
            
            if(s != m.end() && s != i && s->second.first > 0)
            {
                return vector<int> {i->second.second[0],s->second.second[0]};
            }
            
            if(s != m.end() && s == i && s->second.first > 1)
            {
                return vector<int> {i->second.second[0],s->second.second[1]};
            }
            
            
        }
        
        return vector<int>{};
    }
    
};