class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> intervalsCop(intervals);
        vector<int>res;
        preprocessing(intervalsCop);
        sort(intervalsCop.begin(),intervalsCop.end(),comp);
        int sz = intervalsCop.size();
        
        // for(auto v: intervalsCop)
        // {
        //     cout << "(" << v[0] << "," << v[1] << "," << v[2] << ")" << endl;
        // }
        
        for(int i = 0; i < sz; i++)
        {
            int targetEnd = intervals[i][1];
            
            int l = 0;
            int r = sz-1;
            int ret = -1;

            while(l <= r)
            {
                
                int mid = l + (r-l)/2;
                int thisStart = intervalsCop[mid][0];
                
                // cout << "l: " << l << " r: " << r <<  " mid: " << mid << endl;
                
                if(thisStart >= targetEnd)
                {
                    ret = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
                
                // cout << "targetEnd: " << targetEnd << " thisStart: " << thisStart << endl << endl;
                // cout << "l: " << l << " r: " << r <<  " mid: " << mid << endl << endl;
            }
            
            
            
            if(ret == -1)
            {
                res.push_back(-1);    
            }else{
                // cout << "ret: " << ret << endl;
                res.push_back(intervalsCop[ret][2]);    
            }
        }
        
        return res;
        
    }
    
    void preprocessing(vector<vector<int>>& intervalsCop)
    {
        int sz = intervalsCop.size();
        for(int i = 0; i < sz; i++)
        {
            intervalsCop[i].push_back(i);
        }
    }
    
    static bool comp(vector<int> &a , vector<int>&b)
    {
        
        return a[0] < b[0];
    }
    
    
};