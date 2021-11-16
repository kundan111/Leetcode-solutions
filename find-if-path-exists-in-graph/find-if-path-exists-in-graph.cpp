class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        // create a adjacency list
        vector<vector<int>> adjList(n);
        for(auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        
        
        vector<bool> visited(n,false);
        
        dfs(adjList,visited,start);
        
        return visited[end];
    }
    
    void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int curNode)
    {
        if(visited[curNode])
        {
               return;
        }
        visited[curNode] = true;
        
        for(int &node : adjList[curNode])
        {
            if(!visited[node])    
            {
                dfs(adjList,visited,node);
            }   
                
        }
        
    }
    
    
};