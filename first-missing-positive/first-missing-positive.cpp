class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int sz = nums.size();
        int i = 0;
        
        
//         if(sz == 1)
//         {
//             if (nums[0] <= 0)
//             {
//                 return 1;
                
//             }else{
//                 if(nums[0] == 1)
//                 {
//                     return 2;
//                 }else{
//                     return 1;
//                 }
//             }
//         }
        
        
        // cout << "yo1" << endl;
        
        
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
            // cout << "yo2" << endl;
        
        }
        
        return start;
        
    }
};