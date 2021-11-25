class Solution {
private:
    int row,col;
public:
    int getFood(vector<vector<char>>& grid) {
     row = grid.size();
     col = grid[0].size();
        
        //find user current location
        int curRow = 0;
        int curX,curY;
        for(auto &vec : grid)
        {
            auto itr = find(vec.begin(),vec.end(),'*');
            if( itr != vec.end())
            {
                curX = curRow;
                curY = itr-vec.begin();
                break;
            }
            curRow++;
        }
        
        // cout << "curX: " << curX << endl << "curY: " << curY << endl;
      
     
    int ans = 0;
    queue<pair<int, int>> stateQueue;
    stateQueue.push({curX,curY});
        
    vector<vector<bool>> visited(row,vector<bool>(col,false));
    visited[curX][curY] = true;
        
    int dirX[4] = {0,0,-1,1};
    int dirY[4] = {-1,1,0,0};
    
    bool found = false;
    int curLen = 0;
    while(!stateQueue.empty())
    {
        int sz = stateQueue.size();
        
        while(sz--){
            
                auto cur = stateQueue.front();        
                stateQueue.pop();

                if(grid[cur.first][cur.second] == '#')
                {
                    return curLen;
                }

                grid[cur.first][cur.second] = '@';


                

                for(int i = 0; i < 4; i++)
                {
                    int newX = cur.first + dirX[i];
                    int newY = cur.second + dirY[i];

                    if(isValid(newX,newY) && grid[newX][newY] != 'X' && grid[newX][newY] != '@' && !visited[newX][newY])
                    {
                        stateQueue.push({newX,newY});
                        visited[newX][newY] = true;
                    }

                }

        }
        
        curLen++;
        
        
    }
        
    
        
        return -1;
        
                
        
        
        
        
    }
    
    bool isValid(int i, int j)
    {
        return (i >= 0 && i < row) && (j >= 0 && j < col);
    }
};