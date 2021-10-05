class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sz = arr.size();
        
        int prevWinSum = accumulate(arr.begin(),arr.begin()+k,0);
        
        int i = 0;
        int j = k;
        
        int res = prevWinSum/k >= threshold ? 1 : 0;
        
        while(j < sz)
        {
            int curWinSum = prevWinSum - arr[i] + arr[j];
            
            res += curWinSum/k >= threshold ? 1 : 0;
            prevWinSum = curWinSum;
            i++;
            j++;
            
            
        }
        
        return res;
        
        
    }
};