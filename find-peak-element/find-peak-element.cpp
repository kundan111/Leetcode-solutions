class Solution {
public:
    int findPeakElement(vector<int>& nums) {
            int sz = nums.size();
            
            int l = 0;
            int r = sz-1;
        
            
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            
            long long int leftVal = mid-1 >= 0 ? nums[mid-1]: LLONG_MIN;
            long long int rightVal = mid+1 < sz ? nums[mid+1]: LLONG_MIN;
            
            // cout << "leftVal: " << leftVal << endl << "rightVal: " << rightVal<<endl << "nums[mid]: " << nums[mid] ;
            // cout << " mid: " << mid << endl << endl;
            if(leftVal <nums[mid] && nums[mid] > rightVal)
            {
                // cout << "yo" << endl;
                return mid;
            }else if(nums[mid] < rightVal || (nums[mid] < leftVal && nums[mid] < rightVal))
            {
                l = mid+1;
            }else{
                r =mid-1;
            }
        }
        
        return -1;
        
        
    }
    
    
    
};