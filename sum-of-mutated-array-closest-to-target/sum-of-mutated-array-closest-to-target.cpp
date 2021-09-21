class Solution {
private:
    vector<int>prefixSum;    
public:
    int findBestValue(vector<int>& arr, int target) {
        
        
        int sz = arr.size();
        prefixSum.resize(sz);
        
        
        sort(arr.begin(),arr.end());
        
        
        int prev = 0;
        int i = 0;
        int mn = INT_MAX, mx = INT_MIN;
        for(int &val: arr)
        {
            
            mn = min(val,mn);
            mx = max(val,mx);
            
            prefixSum[i] = prev + val;
            prev = prev + val;
            i++;
        }
        
        int l = 0;
        int r = mx;
        
        int diff = INT_MAX;
        
        int res;
        
        int totSum;
        int mid;
        
        while(l <= r)
        {
            mid = l + (r-l)/2;
            
            // find the index of the element equal or greater than mid
            auto itr = lower_bound(arr.begin(),arr.end(),mid);
            int ind = itr - arr.begin();
            
            int numberOflargerElements = sz - ind;
            int sumOfLargerNumbers = numberOflargerElements * mid;
            
            int sumOfSmallerNumbers = ind > 0 ? prefixSum[ind-1] : 0;
            
            totSum = sumOfLargerNumbers + sumOfSmallerNumbers;
            
            // cout << "mid: " << mid << endl << "totSum: " << totSum << endl; 
            
            if(totSum <= target)
            {
                
                // res = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
            
           if (abs(totSum - target) < diff || (abs(totSum - target) == diff && mid < res)) { 
               
                // cout << "yo" << endl;
                 res = mid;
                diff = abs(totSum - target);
            }
            
            // cout << "res: " << res << endl <<  "diff: " << diff << endl << endl;
            
        }
         
       
        
    
        return res;
        
    }
    
    
    
    
};