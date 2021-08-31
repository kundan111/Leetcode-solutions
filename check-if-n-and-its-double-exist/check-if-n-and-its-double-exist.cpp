class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int sz = arr.size();
        for(int i = 0; i < sz-1; i++)
        {
            if(binary_search(arr,i+1,sz-1,2*arr[i]))
            {
                return true;
            }
            if(arr[i] < 0 && ((-1*arr[i]) & 1) == 0)
            {
                if(binary_search(arr,i+1,sz-1,arr[i]/2))
                {
                    return true;
                }
            }
        }
        
        return false;
        
    }
    
    bool binary_search(vector<int>&arr, int l,int r, int target)
    {
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(arr[mid] == target)
            {
                return true;
            }else if(arr[mid] > target)
            {
               r = mid-1; 
            }else{
                l = mid+1;
            }
        }
        return false;
    }
};