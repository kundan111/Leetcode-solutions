class Solution {
public:
    int findKthPositive(vector<int>& arr1, int k) {
        
        int sz = arr1.size();
        vector<int>arr(1001,0);
        for(int val: arr1)
        {
            
            arr[val]++;
        }
        
        int count = 0;
        for(int i = 1; i < 1001; i++)
        {
            
            if(arr[i] == 0)
            {
                count++;
            }
            if(count == k)
            {
                
                return i;
            }
        }
        
        
        int last = arr[sz-1];
        return k - count + 1000;
        
    }
};