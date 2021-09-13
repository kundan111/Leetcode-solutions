class Solution {
    private:
    vector<int> numsCop;
    
public:
    int triangleNumber(vector<int>& nums) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        numsCop = move(nums);
        int sz = numsCop.size();
        // cout << "yo" << endl;
        vector<int>new_sorted(1001,0);
        for(int i = 0; i < sz; i++)
        {
            new_sorted[numsCop[i]]++;
        }
        
        // cout << "yo" << endl;
        
        numsCop.clear();
        
        for(int i = 0; i < 1001; i++)
        {
            int freq = new_sorted[i];
            while(freq)
            {
                numsCop.push_back(i);
                freq--;
            }
        }
        
        

        
        if(numsCop.size() < 3)
        {
            return 0;
        }
     
        // sort(numsCop.begin(),numsCop.end());
        int res = 0;
        // int sz = numsCop.size();
        
        for(int i = 0; i < sz-2;i++)
        {
            for(int j = i+1; j < sz-1; j++)
            {
                int l = j+1;
                int r = sz-1;
                
                while(l <= r)
                {
                    int mid = l + (r-l)/2;
                    int poten = numsCop[mid];
                    
                    if(poten == numsCop[i] + numsCop[j])
                    {
                        r = mid-1;
                        
                    }else if(poten < numsCop[i] + numsCop[j]){
                        
                        int t = bs(mid,r,numsCop[i] + numsCop[j]);
                        res += t-mid+1;
                        r = mid-1;
                    }else{
                        r =mid-1;
                    }
                }
            }
            
        }
        
        return res;
        
    }
    
    int bs(int l, int r, int val)
    {
        int ret;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(numsCop[mid] < val)
            {
                ret = mid;
                l = mid+1;
            }else if(numsCop[mid] >= val)
            {
                r = mid-1;
            }
        }
        return ret;
    }
    
    
};