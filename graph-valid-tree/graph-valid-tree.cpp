class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // if(edges.size() != n - 1) return false;
        vector<vector<int>> g(n);
        for(auto& e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        queue<int> q{{0}};
        vector<int> seen(n, 0);
        while(!q.empty()){
            for(int sz = q.size(); sz > 0; sz--){
                auto cur = q.front();q.pop();
                if(seen[cur] == 1) return false;
                seen[cur]=1;
                for(auto nxt: g[cur]){
                    if(!seen[nxt]) q.push(nxt);                    
                }
            }
            
        }
        return accumulate(begin(seen),end(seen), 0) == n;        
    }
};