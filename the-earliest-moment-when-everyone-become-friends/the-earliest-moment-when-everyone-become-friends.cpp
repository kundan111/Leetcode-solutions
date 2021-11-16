class UnionFind{
    private:
        vector<int> root;
        vector<int> rank;
        int count;
    public:
        UnionFind(int sz)
        {
            root.resize(sz);
            for(int i = 0; i < sz; i++)
            {
                root[i] = i;
            }
            
            rank.resize(sz,1);
            count = sz;
        }
                
        int find(int x)
        {
            if(x == root[x])
            {
                return x;
            }
            
            // path compression
            return root[x] = find(root[x]);
        } 
                
        void unionSet(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);
            
            if(rootX != rootY)
            {
                if(rank[rootX] < rank[rootY])
                {
                   root[rootX] = rootY;
                }else if(rank[rootX] > rank[rootY])
                {
                    root[rootY] = rootX;
                }else{
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
            
                count--;
            }
        }
                
        
        int getCount()
        {
            return count;
        }
    
    
    
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        
        sort(logs.begin(),logs.end(), [](vector<int> & a, vector<int> &b){
            return a[0] < b[0];
            
         });
        
        // for(auto v : logs)
        // {
        //     cout  << "(" <<  v[0] << ","  << v[1] <<  "," <<  v[2] << ") ";
        // }
        
        UnionFind uf(n);
        for(auto log : logs)
        {
            uf.unionSet(log[1],log[2]);
            if(uf.getCount() == 1)
            {
                return log[0];
            }
        }
        
        
        return -1;
        
    }
};