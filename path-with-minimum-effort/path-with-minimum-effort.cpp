class Solution {
    vector<vector<int>> heightCop;
    int row,col;
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        row = heights.size();
        col = heights[0].size();
        heightCop = move(heights);
        
        // cout << "row: " << row << " col: " << col << endl;
        
        
        // vector<vector<bool>>visited(row,vector<bool>(col,false));
        // cout << "2 ka o/p: " << dfs(0,0,2,visited)  << endl;
        
        
        int l = 0;
        int r = 1000000;
        
        int ret = -1;
        while(l <= r)
        {
            vector<vector<bool>>visited(row,vector<bool>(col,false));
            int mid = l + (r-l)/2;
            
            if(dfs(0,0,mid,visited))
            {
                ret = mid;
                r = mid-1;
                // cout << "if" << endl;
            }else{
                
                l = mid+1;
                // cout << "mid: " << mid << endl;
            }
            // cout << "ret: " << ret << endl;
        }
        
        // cout << "l: " << l << " r: " << r << endl;
        
        
        return ret; 
        
        
        // return -1;
    }
    
    
    bool isValid(int i, int j)
    {
        return ((i >=0  && i < row ) && (j >=0 && j < col));
    }
    
    
    bool dfs(int i, int j, int curVal, vector<vector<bool>> &visited)
    {
        if(i == row-1 && j == col-1)
        {   
            // cout << "row: " << row << " col: " << col << endl;
            return true;
        }
        
        visited[i][j] = true;
        
        bool ret1 = false,ret2 = false,ret3 = false,ret4 = false;
        
        if(isValid(i-1,j) && !visited[i-1][j] &&  abs(heightCop[i-1][j] - heightCop[i][j]) <= curVal)
        {
            // cout << "1" << endl;
            // cout << "calling i: " <<  i-1 << " calling j: " << j << endl;
            ret1 =  dfs(i-1,j, curVal,visited);
        }
        
        if(isValid(i,j+1) && !visited[i][j+1] &&  abs(heightCop[i][j+1] - heightCop[i][j]) <= curVal)
        {
            // cout << "2" << endl;
            // cout << "calling i: " <<  i << " calling j: " << j+1 << endl;
            ret2 = dfs(i,j+1, curVal,visited);
        }
        
        if(isValid(i+1,j) && !visited[i+1][j] &&  abs(heightCop[i+1][j] - heightCop[i][j]) <= curVal)
        {
            // cout << "3" << endl;
            // cout << "calling i: " <<  i+1 << " calling j: " << j << endl;
            ret3  = dfs(i+1,j, curVal,visited);
        }
        
        if(isValid(i,j-1) && !visited[i][j-1] &&  abs(heightCop[i][j-1] - heightCop[i][j]) <= curVal)
        {
            // cout << "4" << endl;
            // cout << "calling i: " <<  i << " calling j: " << j-1 << endl;
            ret4  = dfs(i,j-1, curVal,visited);
        }
        
        return ret1 || ret2 || ret3 || ret4;
        
        
    }
    
    
};