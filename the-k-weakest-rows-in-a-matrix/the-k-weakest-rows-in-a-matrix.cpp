class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> str_vec;
        int r = mat.size();
        int c = mat[0].size();
        int i = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        
        for(auto row : mat)
        {
            pq.push({strength(row,0,c-1),i});
            if(pq.size()>k){
                pq.pop();
            }
            i++;
        }
        vector <int> ret;
        
        i = 0;
        
        // while(!pq.empty())
        // {
        //     auto r = pq.top();
        //     pq.pop();
        //     cout << "{ " << r.first << "," << r.second << " }" << endl;
        // }
        
       
        while(k)
        {
            auto val = pq.top();
            pq.pop();
            ret.push_back(val.second);
            k--;
            
        }
        
        reverse(ret.begin(),ret.end());
        return ret;
        
        
        
    }
    
    struct comp {
    
       bool operator()(pair<int,int>a,pair<int,int>b)
        {
            return a.first != b.first ? (a.first < b.first) : (a.second < b.second);
        }
        
    };
    
    int strength(vector<int> v,int l, int r)
    {
        int ret = -1;
        
        int oriCol = r+1;
        
        while(l <= r)
        {
            
            int mid = l + (r-l)/2;
            if(v[mid] == 0)
            {
                ret = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
            
        }
        
        return ret == -1 ? oriCol : ret;
    }
};