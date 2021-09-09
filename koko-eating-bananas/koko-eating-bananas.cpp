class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        
        // cout << "l: " << l << " r: " << r << endl;
        
        return bs(piles,l,r,h);
    }
    
    int bs(vector<int>& piles, int l, int r,int hours)
    {
        
         // search for first true
        int ret;
        while(l <= r)
        {
            
            int mid = l + (r-l)/2;
            
            
            // cout << "ret: " << ret << " mid: " << mid << endl;
            
            if(ifItisSufficient(piles,mid,hours))
            {
                ret = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
            
        }
        return ret;
        
    }
    
    bool ifItisSufficient(vector<int>& p,int val, int &targetHours)
    {
        int i = 0;
        int sz = p.size();
        int hours = 0;
        
        while(i < sz)
        {
            hours += p[i]%val == 0 ? p[i]/val :  p[i]/val + 1;
            if(hours > targetHours)
            {
                return false;
            }
            i++;
        }
        
        return true;
    }
};