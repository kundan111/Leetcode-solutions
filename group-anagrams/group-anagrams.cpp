class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        
        
        vector<pair<string,string>> m;
        int sz = s.size();
	
        for (int i = 0; i < sz; i++) {
            string cur = s[i];
            string rev = cur;
            sort(rev.begin(),rev.end());
            m.push_back(make_pair(rev,cur));
        }
        
        sort(m.begin(),m.end(),comp);
        
        
        vector<vector<string>> res;
        
        string prev = "@";
        
        int i =-1;
        
        
        for(auto p: m)
            
        {
            if(p.first == prev)
            {
                res[i].push_back(p.second);
                
            }else{
                res.push_back(vector<string>());
                i++;
                res[i].push_back(p.second);
                prev = p.first;
                
            }
        }
        
        return res;
        
        
        
        
    }
    
    static bool comp(pair<string,string>p1,pair<string,string>p2)
    {
        return p1.first < p2.first;
    }
};