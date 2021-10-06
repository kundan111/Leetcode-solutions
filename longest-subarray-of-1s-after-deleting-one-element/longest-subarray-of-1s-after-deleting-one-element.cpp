class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>> se;
        int orisz = nums.size();
        
        int i = 0;
        while( i < orisz)
        {
            if(nums[i])
            {
               pair<int,int>t;
               t.first = i;
               int j = i;
               while(j < orisz && nums[j])
               {
                   j++;
               }
                i = j;
               t.second = j-1;
                se.push_back(t);
                
            }else{
                i++;
            }
        }
        
        int sz = se.size();
        
        
        if(se.size() == 0)
        {
            return 0;
        }else if(se.size() == 1)
        {
            return (se[0].second - se[0].first) + 1 == orisz ? se[0].second - se[0].first : se[0].second - se[0].first + 1;
        }else{
            
            int maxIndiLen = se[0].second - se[0].first + 1;
            int prevE = se[0].second;
            int prevS = se[0].first;
            int mergedLen = 0;
            
            int k = 1;
            while( k < sz)
            {
                if(se[k].first - prevE == 2)
                {
                    mergedLen = max(mergedLen, se[k].second - se[k].first + 1 + prevE - prevS + 1);
                    
                }
                
                maxIndiLen = max(maxIndiLen, se[k].second - se[k].first + 1);
                
                prevS = se[k].first;
                prevE = se[k].second;
                
                k++;
                
            }
            
            
            return max(maxIndiLen, mergedLen);
            
            
        
        }
        
        
        
        
        
        
        
    }
};