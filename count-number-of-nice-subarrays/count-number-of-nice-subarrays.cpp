class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        for(int &x:a)
            x=x%2;
        unordered_map <int,int> mp;
        mp[0]=1;
        int csum=0;
        int ans=0;
        for(int i=0;i<a.size();i++){
            csum+=a[i];
            if(mp.count(csum-k))
            {
                // cout << "mp[" << csum-k << "]: " << mp[csum-k] << endl;
                ans+=mp[csum-k];
            }
                
            mp[csum]++;
            // cout << "ans: " << ans << endl;
        }
        
        // for(auto val : mp)
        // {
        //     cout << val.first << " -> " << val.second << endl; 
        // }
        
        return ans;
    }
};