class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            
        sort(intervals.begin(),intervals.end(), comp);
        
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        
        int sz = intervals.size();
        
        for(int i = 1; i < sz ; i++)
        {
            if(res.back()[1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            }else{
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
    
    
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
};