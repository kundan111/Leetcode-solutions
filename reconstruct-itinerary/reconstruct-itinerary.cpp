class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string,priority_queue<string,vector<string>,greater<string>> > m;
        
        for(auto item : tickets)
        {
            m[item[0]].push(item[1]);
        }
        
        vector<string> res;
       
        string starting = "JFK";
        
        stack<string> s;
        s.push("JFK");
        
        
        while(!s.empty())
        {
            string cur = s.top();
            if(m[cur].size() == 0 || m.find(cur) == m.end())
            {
                res.push_back(cur);
                s.pop();
            }else{
                auto next = m[cur].top();
                m[cur].pop();
                s.push(next);
            }
            
            
        }
        
        reverse(res.begin(),res.end());
        
        
        
        
        return res;
    }
    
    
    void dfs(unordered_map<string,priority_queue<string,vector<string>,greater<string>> > &m, string &curAirport, vector<string> &path)
    {
        path.push_back(curAirport);
        if(m[curAirport].size() == 0)
        {
            return;
        }
        
        
        while(m[curAirport].size())
        {
            string next = m[curAirport].top();
            m[curAirport].pop();
            
            dfs(m,next,path);
        }
    }
};