class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int s1 = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int s2 = accumulate(bobSizes.begin(),bobSizes.end(),0);
        
        int c = (s2-s1)/2;
        
        
        unordered_map<int,int> m;
        
        for(int val: bobSizes )
        {
            m[val]++;
        }
        
        
        for(int &x : aliceSizes) {
            
            if(m.count(c+x)){
                return {x, c+x};
            }
            
        }
        return {};
        
    }
    
    
    
};