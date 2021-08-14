class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
          bitset<5>b;
          int res = 0;
        
          int sz = nums.size();
        
        for(int i = 0; i < (1 << sz); i++)
        {
            bitset<12>b(i);
            int temp_xor = 0;
            
            for(int j = 0; j < 12; j++)
            {
                if(b[sz-1-j] == 1)
                {
                    temp_xor = temp_xor ^ nums[sz-1-j];
                }
            }
            res = res + temp_xor;
        }
        
        return res;
    }
};