class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
        int sz = graph.size();
        vector<vector<int>>res;
        
        vector<int> path = {};
        dfs(graph,res,0,sz-1,path);
        
        return res;
        
        
    }
    
    void dfs(vector<vector<int>>& graph,  vector<vector<int>> &res, int curNode, int target, vector<int> &path)
    {
          if(curNode == target)
          {
              path.push_back(target);
              res.push_back(path);
              return;
          }
        
         path.push_back(curNode);
         for(int val : graph[curNode])
         {
             dfs(graph,res,val,target,path);
             path.pop_back();
         }
        
        
        
    }
    
    
};