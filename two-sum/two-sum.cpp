class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,vector<int>> m;
        int numSz = nums.size();
        for(int i = 0; i < numSz; i++)
        {
            m[nums[i]].push_back(i);
        }

        auto itr = m.begin();
        for(; itr != m.end(); itr++)
        {
             auto searchItr = m.find(target - itr->first);
             if( searchItr != m.end())
             {
                 if( searchItr != itr)
                 {	
                     return {itr->second[0], searchItr->second[0]};
                 }else{
                     if(itr->second.size() > 1)
                    {
                       return {itr->second[0], itr->second[1]};
                    }
                }
             }

        }

        return {};

    }
    
};