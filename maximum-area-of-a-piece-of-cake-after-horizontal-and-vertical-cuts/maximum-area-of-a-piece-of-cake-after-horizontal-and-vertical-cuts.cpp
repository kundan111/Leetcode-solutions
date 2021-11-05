class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
     
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxWidth = INT_MIN;
        int maxHeight = INT_MIN;
        
        int prev = 0;
        int wsz = horizontalCuts.size();
        
        for(int i = 0; i < wsz; i++)
        {
             maxWidth = max(maxWidth,horizontalCuts[i] - prev);
             prev = horizontalCuts[i];
        }
        
        
        maxWidth = max(maxWidth, h - horizontalCuts[wsz-1]);
        
        
        prev = 0;
        
        int hsz = verticalCuts.size();
        for(int i = 0; i < hsz; i++)
        {
             maxHeight = max(maxHeight,verticalCuts[i] - prev);
             prev = verticalCuts[i];
        }
        
        
        
        maxHeight = max(maxHeight, w - verticalCuts[hsz-1]);
        
        
        return (1LL*maxWidth*1LL*maxHeight)%1000000007;
        
        
    }
};