class LockingTree {
public:
    int sz;
    unordered_map<int,vector<int>>tree;
    vector<int>lock_state; // -1 means unlock; +ve value means user of the node
    vector<int>parentCop;
    LockingTree(vector<int>& parent) {
        sz = parent.size();
         
        for(int i = 0; i < sz; i++)
        {
            tree[parent[i]].push_back(i);
        }
        lock_state.resize(sz, -1); // initally all unlocked
        parentCop = move(parent);
        
    }
    
    bool lock(int num, int user) {
        if(lock_state[num] > 0)
        {
            // already locked
            return false;
        }
        lock_state[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(lock_state[num] == -1)
        {
            // already unlocked
            return false;
        }
        if(lock_state[num] != user)
        {
            // not the original user
            return false;
        }
        // unlock it
        lock_state[num] = -1;
        return true;
        
    }
    
    bool upgrade(int num, int user) {
        
        if(lock_state[num] > 0)
        {
            // already locked
            return false;
        }
        // node is unlocked
        
        bool b2 = areAllAncestorsUnlocked(num);
        
        if(!b2)
        {
            return false;
        }
        
        
        bool b1 = checkAndUnlockDecendents(num);
        
        
        if( b1 && b2)
        {
            // lock it
            lock_state[num] = user;
            return true;
        }
        
        return false;
        
    }
    
    bool checkAndUnlockDecendents(int num)
    {
        bool fl = false;
        if(tree.find(num) == tree.end()) // leaf -> No children
        {
            return false; // there are no decendents to unlock;
        }
        
        
        
        // Non leaf node
        
        queue<int> q;
        for(int v: tree[num])
        {
            q.push(v);
        }
        
        while(!q.empty())
        {
            // check if locked
            int cur = q.front();
            if(lock_state[cur] > 0)
            {
                fl = true;
                lock_state[cur] = -1; // unlock it
            }
            q.pop();
            if(tree.find(cur) != tree.end()) // not a leaf node
            {
                for(int val: tree[cur])
                {
                    q.push(val);
                }
            }
        }
        
        return fl;
    }
    
    
    bool areAllAncestorsUnlocked(int num)
    {
        int ind = parentCop[num];
        while( ind != -1)
        {
            if(lock_state[ind] > 0) // already locked
            {
                return false;
            }
            ind = parentCop[ind];
        }
        
        return true;
    }
    
};

/*
2 -> (5 6 )
1 -> (3 4 )
-1 -> (0 )
0 -> (1 2 )

*/

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */