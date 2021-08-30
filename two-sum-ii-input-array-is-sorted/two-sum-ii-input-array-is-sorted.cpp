class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {
        int sz = vec.size();
        int s = 0;
        int e = sz-1;
        vector<int>res;
        while(s < e)
        {
            int curSum = vec[s] + vec[e];
            if(curSum > target)
            {
                e--;
            }else if(curSum < target)
            {
                s++;
            }else{
                res = {s+1,e+1};
                return res;
            }
        }
        
        
        return {};
    }
};