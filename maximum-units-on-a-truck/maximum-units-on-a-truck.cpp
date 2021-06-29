class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // counting sort
        vector<int> vec(1001,-1);
        
        for(auto cur: boxTypes)
        {
            if(vec[cur[1]] == -1)
            {
                vec[cur[1]] = cur[0];
                
            }else{
                vec[cur[1]] += cur[0];
            }
        }
        
        int curSize = truckSize;
        int res = 0;
        for( int i = 1000; i >= 0; i--)
        {
            if(vec[i] == -1)
                continue;
            if(curSize < vec[i])
            {
                res =  res + curSize*i;
                return res;
            }else{
                res = res + i*vec[i];
                curSize = curSize - vec[i];
            }
        }
        
        return res;
        
    }
};