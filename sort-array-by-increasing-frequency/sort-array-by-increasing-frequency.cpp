class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
            
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> v;
        int sz = nums.size();
        
        int i = 0;
        
        while(i < sz)
        {
            int cur = nums[i];
            // cout << "yo" << endl;
            int count = 0;
            int j = i;
            while(j < sz && nums[j] == cur)
            {
                j++;
                count++;
            }
            v.push_back({cur,count});
            i = j;
        }
        
        
        sort(v.begin(),v.end(),comp);
        
//         for(auto val: v)
//         {
//             cout << "(" << val.first << ", " << val.second << ") " ; 
//         }
        
//         cout << endl;
        
        i = 0;
        sz = v.size();
        int j = 0;
        while( i < sz)
        {
            
            int curEle = v[i].first;
            int freq = v[i].second;
            
            while(freq)
            {
                nums[j] = curEle;
                freq--;
                j++;
            }
            i++;
        }
        
        
        
        
        return nums;
    }
    
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second < b.second)
        {
            return true;
        }else if(a.second > b.second)
        {
            return false;
        }else{
            return a.first > b.first;
        }
    }
};