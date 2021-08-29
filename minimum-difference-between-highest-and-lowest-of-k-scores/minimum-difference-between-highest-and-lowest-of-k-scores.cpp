class Solution {
public:
    int minimumDifference(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int i = 0;
        int min_diff = INT_MAX;
        int sz = v.size();
        while(i < sz)
        {
            int s = i;
            int e = i+k;
            if(v.begin() + e <= v.end())
            {
                int min_ele = *min_element(v.begin()+s, v.begin()+e);
                int max_ele = *max_element(v.begin()+s, v.begin()+e);
                
                min_diff = min(min_diff, max_ele-min_ele);
            
            }
             i++;
        }
        return min_diff;
    }
};