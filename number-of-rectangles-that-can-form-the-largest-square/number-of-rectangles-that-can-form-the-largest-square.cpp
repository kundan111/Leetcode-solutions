class Solution {
public:
    int res = 0;
    int maxLen = INT_MIN;
    unordered_map<int,int>m;
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int sz = rectangles.size();
        for(int i = 0; i < sz;i++)
        {
            vector<int> cur = rectangles[i];
            int min = cur[0];
            if(min > cur[1])
                min = cur[1];
            
            m[min]++;
            if(min >= maxLen)
            {
                maxLen = min;
                res = m[min];
            }
        }
        return res;
    }
};