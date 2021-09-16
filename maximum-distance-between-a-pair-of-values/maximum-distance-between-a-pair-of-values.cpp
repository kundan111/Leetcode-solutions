class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    
        int res = 0;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        
        
        for(int i = 0; i < sz1 ; i++)
        {
            
                int l = i;
                int r = sz2-1;
                
                while(l <= r)
                {
                    int mid = l + (r-l)/2;
                    int curVal = nums2[mid];
                    // cout << "nums1[i]: " << nums1[i] << " curVal: " << curVal;
                    // cout << "l: " << l << " r: " << r << " mid: " << mid << endl;   
                    if(curVal >= nums1[i])
                    {
                        res = max(res, mid-i);
                        l = mid+1;
                    }else{
                        r = mid-1;
                    }
                    // cout << "res: " << res << endl  << endl;
                }
            
        }
        
        return res;
        
    }
    
    
};