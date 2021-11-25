class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int sz = nums.size();
        vector<int> res(sz);
        for(int i = 0; i < sz; i++)
        {
            int cur = nums[i];
            int j = i;
            int curIndx = j;
            bool found = false;
            while( j < sz )
            {
                if(nums[j] > cur)
                {
                    res[curIndx] = nums[j];
                    found = true;
                    break;
                }
                j++;
            }
            
            if(!found)
            {
                int s = 0;
                while(s < sz && s < curIndx)
                {
                    if(nums[s] > cur)
                    {
                        res[curIndx] = nums[s];
                        found = true;
                        break;
                    }
                    s++;
                }
                
            }
            
            if(!found)
            {
                res[curIndx] = -1;
            }
            
            curIndx++;
            
        }
        
        return res;
        
        
    }
    
    
};