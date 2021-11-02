class Solution {
private:
    int row,col;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        row = isConnected.size();
        col = isConnected[0].size();
        
        vector<int>visited(row, false);
        
        int res = 0;
        for(int i = 0; i < row; i++)
        {
            if(!visited[i])
            {
                dfs(visited, isConnected, i);
                res++;
            }
        }
        
        return res;
    }
    
    void dfs(vector<int> &visited, vector<vector<int>> &isConnected, int cur)
    {
        for(int i = 0; i < col; i++)
        {
            if(isConnected[cur][i] && !visited[i])
            {
                visited[i] = true;
                dfs(visited, isConnected, i);
            }
            
        }
    }
};