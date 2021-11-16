
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
            
            vector<vector<int>> adjList(n);
            for(auto v : edges)
            {
                adjList[v[0]].push_back(v[1]);
                adjList[v[1]].push_back(v[0]);
            }
        
            /*int i = 0;
            for(auto v : adjList)
            {
                cout << i << " -> ";
                for(int r : v)
                {
                    cout << r << " ";
                }
                cout << endl;
                i++;
            }
        */
        
        vector<bool> visited(n,false);
        if (hasCycle(adjList, 0, visited, -1))
            return false;
        
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) 
                return false;
        }
        
        return true;
                
    
                
        
    }
    
    bool hasCycle(vector<vector<int>> &adjList, int u, vector<bool> &visited, int parent) {
        visited[u] = true;
        
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            
            if ((visited[v] && parent != v) || (!visited[v] && hasCycle(adjList, v, visited, u)))
                return true;
        }
        
        return false;
    }
    
    
    
    
    
};