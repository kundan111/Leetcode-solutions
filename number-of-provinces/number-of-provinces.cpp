class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
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

    void unionSet(int x, int y) {
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
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
private:
    int row,col;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        row = isConnected.size();
        col = isConnected[0].size();
        
        
        UnionFind uf(row);
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < row; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    uf.unionSet(i,j);
                }
            }
        }
        
        return uf.getCount();
    }
    
};