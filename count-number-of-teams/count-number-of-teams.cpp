class Solution {
public:
    int numTeams(vector<int>& r) {
        
        int sz = r.size();
        
        int res = 0;
        
        for(int j = 0; j < sz; j++)
        {
            int leftSmaller = 0, rightGreater = 0, leftGreater = 0, rightSmaller = 0;
            
            for(int i = 0; i < j; i++)
            {
                if(r[i] < r[j])
                {
                    leftSmaller++;
                }else if(r[i] > r[j])
                {
                    leftGreater++;
                }
            }
            
            for(int k = j+1; k < sz; k++)
            {
                if(r[j] < r[k])
                {
                  rightGreater++;   
                }else if(r[j] > r[k])
                {
                 rightSmaller++;   
                }
            }
            
            res += leftSmaller*rightGreater + leftGreater*rightSmaller;
        }
        
        return res;
    }
};