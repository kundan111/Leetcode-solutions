class Solution {
public:
    static vector<int> v;
    
    int getKth(int lo, int hi, int k) {
        
        
        
        
        int sz = hi-lo+1;
        vector<int> res(sz);
        
        std::iota(res.begin(), res.end(), lo);
        
        
        
       
       std::nth_element(res.begin(),res.begin()+k-1,res.end(),comp) ;
        
        return *(res.begin()+k-1);
        
        
    }
    
    static bool comp (int i, int j) { 
            int x = compute(i);
            int y = compute(j); 
            return x == y ? i < j : x < y;
        }
    
    
    static int compute(int val)
    {
        
        if(v[val] != -1)
            return v[val];
        
        
        
        if(val == 1)
            return 0;
        int cal;
        if(val & 1)
        {
             cal = compute(3*val + 1);
        }else{
            cal = compute(val/2); 
        }
        
        return v[val] = 1 + cal;
        
    }
    
};

vector<int>Solution::v(1000001,-1);