class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int sz = nums.size();
        vector<int> prefSum(sz+1);
        
        prefSum[0] = 0;
        
        for(int i = 1; i < sz+1; i++)
        {
            prefSum[i] = prefSum[i-1] + (nums[i-1]%2 == 1 ? 1 : 0); 
        }
        
        int res = 0;
        
        // cout << "sz+1: " << sz+1 << endl;
        
        for(int i = 0; i < sz+1; i++)
        {
            // cout << "prefSum[i] + k: " << prefSum[i] + k << endl; 
            int l = bs(prefSum,prefSum[i] + k,true);
            int u = bs(prefSum,prefSum[i] + k,false);
            
            if(l != -1 && u != -1)
            {
                res += u - l +1;
                
            }
            
        }
        
        return res;
        
        
        
        
    }
    
    int bs(vector<int>& nums, int target, bool first)
    {
        int l = 0;
        int r = nums.size()-1;
        
        int res = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            {
                res = mid;
                if(first)
                {
                    r = mid-1;    
                }else{
                    l = mid+1;
                }
                
            }else if(nums[mid] > target)
            {
                
                    r = mid-1;
            }else{
               
               l = mid+1; 
            }
        }
        
        return res;
        
        
    }
    
    
};