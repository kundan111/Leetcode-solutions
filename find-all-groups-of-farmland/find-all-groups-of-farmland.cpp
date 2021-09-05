class Solution {
public:
    int row,col;
    vector<vector<int>> res;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        row = land.size();
        col = land[0].size();
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                if(land[i][j] == 1)
                {
                    vector<int> temp = {-1,-1};
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    
                    dfs(land,i,j,temp);
                    
                    ans.push_back(temp[0]);
                    ans.push_back(temp[1]);
                    
                    res.push_back(ans);
                    
                }
            }
        }
        
        
        return res;
        
        
    }
    
    bool isValid(int i,int j)
    {
        return (i >=0 && i < row) && (j >=0 && j < col);
    }
    
    void dfs(vector<vector<int>>& land, int i, int j, vector<int> &temp)
    {
        if(isValid(i,j) && land[i][j] == 1)
        {
            land[i][j] = 2; // mark visited
            if(temp[0] < i || temp[1] < j)
            {
                temp[0] = i;
                temp[1] = j;
            }
            // call all four directions
            dfs(land,i-1,j,temp);
            dfs(land,i,j+1,temp);
            dfs(land,i+1,j,temp);
            dfs(land,i,j-1,temp);
        }
        
    }
};