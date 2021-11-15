class UnionFind{
private:
    vector<int>root;
    vector<int> rank;
    int count;
public:
    UnionFind(int sz): root(sz), rank(sz),count(sz) {
        
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    bool unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            
            count--;
            return true;
            
        }else{
            return false;
        }
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
                return false;
            }
        }
        return true;
    }
    
    int getCount()
    {
        return count;
    }
    
    
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        
        UnionFind uf(n);
        for(auto v : edges)
        {
            uf.unionSet(v[0],v[1]);
        }
        
        return uf.getCount();
        
        
    }
};