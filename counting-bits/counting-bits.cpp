class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i = 0; i <= n; i++)
        {
            res[i] = res[i/2] + i%2;
            
        }
        
        return res;
    }
    
};