class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sz = arr.size();
        vector<int> v(sz+1,0);
        
        int prev = 0;
        for(int i = 1; i < sz+1;i++)
        {
            v[i] = arr[i-1] + prev;
            prev = v[i];
        }
        
        int res = 0;
        
        for(int i = 0; i < sz; i++)
        {
            for(int j = i ; j < sz; j = j+2)
            {
                res = res + v[j+1] - v[i];
                
            }
        }
        
        
        return res;
    }
};