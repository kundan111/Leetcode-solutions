class Solution {
    private:
        string nums1Cop;
        string nums2Cop;
        int m;
        int n;
        vector<vector<int>>mp;
public:
    int longestCommonSubsequence(string text1, string text2) {
        nums1Cop =  move(text1);
        nums2Cop =  move(text2);
        
        m = nums1Cop.size();
        n = nums2Cop.size();
        
        
        mp.resize(m+1,vector<int>(n+1,-1));
        return helper(0,0);
    }
    int helper(int i, int j)
    {
        if(mp[i][j] != -1)
        {
            return mp[i][j];
        }
        if( i == m || j == n)
            return mp[i][j] = 0;
        if(nums1Cop[i] == nums2Cop[j])
        {
            return mp[i][j] = max(1 + helper(i+1,j+1), max(helper(i+1,j),helper(i,j+1)));
        }else{
            return mp[i][j] = max(helper(i+1,j),helper(i,j+1));
        }
    }
};