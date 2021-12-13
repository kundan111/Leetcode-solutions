class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        
        unordered_map<int,int> m;
        vector<int> res;
        
        for(int i = 0; i < v.size(); i++){
            if(m.count(target-v[i])){
                return {i,m[target-v[i]]};
            }
            m[v[i]] = i;
        }
        
        return {};
	    
	    
    }
};