class TimeMap {
public:
    /** Initialize your data structure here. */
    private:
    unordered_map<string,vector<pair<int,string>>>m;
        
    public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
            
        m[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end())
        {
            return "";
        }else{
            int l = 0;
            int r = m[key].size()-1;
            
            return bs(l,r,timestamp,key);
        }
    }
    
    string bs(int l,int r,int timestamp,string key)
    {
        string  ret = "";
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            int curTime = m[key][mid].first;
            if(curTime == timestamp)
            {
                return m[key][mid].second;
            }else if(curTime > timestamp)
            {
                r = mid-1;
            }else{
                ret = m[key][mid].second;
                l = mid+1;
            }
        }
        
        return ret;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
*/