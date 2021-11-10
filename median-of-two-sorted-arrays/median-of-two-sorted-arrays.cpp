class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        
        
        
        int f = 0;
        int s = 0;
        
        int medianPos = (sz1+sz2)/2;
        
        
        if((sz1 == 0 || sz2 == 0) && (sz1 != 0  && sz2 != 0))
        {
            if(sz1)
            {
                // cout << "yo" << endl;
                return sz1 & 1 ? nums1[sz1/2] : (double)(nums1[sz1/2] + nums1[sz1/2 - 1])/2;
            }else{
                return sz2 & 1 ? nums2[sz2/2] : (double)(nums2[sz2/2] + nums2[sz2/2 - 1])/2;
            }
        }
        
        int count = -1;
        int cur;
        bool flag = false;
        int midVal1,midVal2;
        bool flag1 = false, flag2 = false;
        while((f < sz1 || s < sz2) && !flag)
        {
            if(f < sz1 && s < sz2)
            {
                if(nums1[f] < nums2[s])
                {
                    cur = nums1[f];
                    f++;
                }else{
                    cur = nums2[s];
                    s++;
                }
            }else{
                if(f == sz1)
                {
                    cur = nums2[s];
                    s++;
                }else{
                    cur = nums1[f];
                    f++;
                }
            }
            count++;
            if(count == medianPos - 1)
            {
                flag1 = true;
                midVal1 = cur;
            }
            if(count == medianPos)
            {
                flag2 = true;
                midVal2 = cur;
            }
            
            if(flag1 && flag2)
            {
                flag = true;
            }
        }
        
        // cout << "midVal1: " << midVal1 << endl << "midVal2: " << midVal2 << endl;
        
        if((sz1 + sz2) & 1)
        {
            return midVal2;
        }else{
            return (double)(midVal2 + midVal1)/2;
        }  
            
        
    }
};