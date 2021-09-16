class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    
        int res = 0;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        
        int i = 0;
        int j = 0;
        
        while(i < sz1 && j < sz2)
        {
         
            if(nums1[i] > nums2[j])
            {
                i++;
            }else{
                res = max(res,j-i);
                j++;
            }
            
        }
        
        return res;
        
    }
    
    
};