class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int res = 0;
        unordered_set<int>s;
        for(int val : nums)
        {
            if(s.find(val) != s.end())
            {
                return true;
            }
            
            s.insert(val);
            
        }
        
        
        return false;
    }
};