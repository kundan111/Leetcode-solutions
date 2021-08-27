class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> str_vec;
        int r = mat.size();
        int c = mat[0].size();
        int i = 0;
        for(auto row : mat)
        {
            str_vec.push_back({strength(row,0,c-1),i});
            i++;
        }
        
        sort(str_vec.begin(),str_vec.end(),comp);
        
        vector <int> ret;
        
        i = 0;
        while(k)
        {
            ret.push_back(str_vec[i].second);
            k--;
            i++;
        }
        
        return ret;
        
        
        
    }
    
    static bool comp(pair<int,int>a,pair<int,int>b)
    {
        return a.first != b.first ? (a.first < b.first) : (a.second < b.second);
    }
    
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