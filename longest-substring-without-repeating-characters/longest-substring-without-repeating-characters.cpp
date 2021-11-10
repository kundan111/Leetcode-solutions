class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int>tracker(128,-1);
        int left = 0;
        int right = 0;
        
        int sz = s.size();
        
        int res = 0;
        while(right < sz)
        {
            char curChar = s[right];
            int indx = tracker[(int)curChar];
            
            
            if(indx != -1 && indx >= left && indx < right)
            {
                left = indx + 1;
            }
            
            res = max(res, right-left+1);
            tracker[(int)curChar] = right;
            right++;
        }
        return res;
    }
};