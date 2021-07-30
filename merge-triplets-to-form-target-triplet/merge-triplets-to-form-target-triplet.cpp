class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<int> res(3,0);
        for(auto val: triplets)
        {
            if(val[0] <= target[0] && val[1] <= target[1] && val[2] <= target[2])
            {
                res = {max(res[0],val[0]),max(res[1],val[1]),max(res[2],val[2])};
            }
        }
        
        return res == target;
    }
    
};