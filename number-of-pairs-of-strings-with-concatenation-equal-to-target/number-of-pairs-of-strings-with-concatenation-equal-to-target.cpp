#include <string>
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        
        int sz = nums.size();
        int count = 0;
        for(int i = 0;i < sz; i++)
        {
            if(contains(target,nums[i]))
            {
                string rest = target.substr(nums[i].size());
                for(int j = 0; j < sz; j++)
                {
                        if(i != j)
                        {
                            if(rest == nums[j])
                            {
                                count++;
                            }
                        }
                }
            }
            
        }
        
        return count;
        
    }
    
    bool contains(string &haystack, string &needle)
    {
        int hz = haystack.size();
        int nz = needle.size();
        
        if(nz > hz)
        {
            return 0;
        }
        
        int i = 0;
        int j = 0;
        while(i < nz && j < hz)
        {
            if(haystack[j] == needle[i])
            {
                i++;
                j++;
            }else{
                return 0;
            }
        }
        
        return 1;
    }
};