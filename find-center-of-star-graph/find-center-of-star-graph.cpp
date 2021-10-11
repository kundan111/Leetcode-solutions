class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto r1 = edges[0];
        auto r2 = edges[1];
        
        for(int n1 : r1)
        {
            for(int n2 : r2)
            {
                if(n1 == n2)
                {
                    return n1;
                }
            }
        }
        
        
        return -1;
    }
};