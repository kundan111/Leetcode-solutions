class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> v{a,b,c};
        int res = 0;
        while( (v[0] && v[1]) || (v[1] && v[2]) || (v[0] && v[2]))
        {
        
            res++;
            sort(v.begin(),v.end());
            v[1]--;
            v[2]--;
        }
        
        return res;
        
        
    }
    
   
};