class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        
         
        unordered_map<int,int> m;
        for(int &val : nums )
        {
            m[val]++;
        }
        
        
        int start = 1;
        
        while(true)
        {
            if(m.count(start) == 0)
            {
                return start;
            }
            start++;
        }
        
        return -1;
        
        /*
        sort(nums.begin(),nums.end());
        int sz = nums.size();
        int i = 0;
        
        int start = 1;
        while( i < sz)
        {
            while(i < sz && nums[i] <= 0)
            {
                i++;
            }
            if(i < sz && nums[i] != start)
            {
                return start;
            }
            if(i == sz)
            {
                return 1;
            }
            
            while(i < sz && nums[i] == start)
            {
                i++;
            }
            
            start += 1;
            
        
        }
        
        return start;
        
        */
        
    }
};