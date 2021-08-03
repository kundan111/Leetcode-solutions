class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        
       set<vector<int> > s;
        int n = nums.size();
        int last = pow(2,n);
       for(int i = 0; i < last; i++)
       {
           bitset<10>b(i);
           vector<int>temp;
           for(int p = 0; p < n ; p++)
           {
               if(b[p] == 1)
               {
                   temp.push_back(nums[n-1-p]);
               }
           }
           sort(temp.begin(),temp.end());
           s.insert(temp);
           
       }
        
        vector<vector<int>> v(s.begin(),s.end());
        
        return v;
        
        
    }
};