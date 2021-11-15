class UnionFind{
private:
    vector<int>root;
public:
    UnionFind(int sz)
    {
        root.resize(sz);
        for(int i = 0; i < sz; i++)
        {
            root[i] = i;
        }
    }
    
    int find(int x)
    {
        return root[x];
    }
    
    bool unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX != rootY)
        {
            for(int i  = 0; i < root.size(); i++)
            {
                if(root[i] == rootY)
                {
                    root[i] = rootX;
                }
            }
            return true;
        }
        // cout << "yo" << endl;
        return false;
    }
    
    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
    
    void printIt()
    {
        cout << endl;
        for(int i = 0; i < root.size(); i++)
        {
            cout << root[i] << " ";
        }
        cout << endl;
    }
    
    bool checkForConnectdness()
    {
        
        int val = root[0];
        for(int i = 0; i < root.size(); i++)
        {
            if(root[i] != val)
            {
                // cout << "ghoda" << endl;
                return false;
            }
        }
        return true;
    }
    
    
    
};

class Solution {

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        UnionFind uf(n);
        for(int i= 0; i < edges.size(); i++)
        {
            if(!uf.unionSet(edges[i][0],edges[i][1]))
            {
                return false;   
            }
        }
        
        if(uf.checkForConnectdness())
        {
            return true;
        }
        
        return false;
    }
    
    
    /*void dfs(vector<vector<int>>& edges,int vertex, vector<int,int> curEdge)
    {
        if(v[vertex] == 0)
        {
            v[vertex]++;
            for(int i = 0; i < edges.size(); i++)
            {
                if((edges[i] != curEdge) && (edges[i][0] == curEdge || edges[i][1] == curEdge ))
                {
                    
                    dfs(edges, vertex,edges[i]);
                }
            }
        }
    }*/
    
};