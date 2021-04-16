class Solution {
public:
 vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        res.resize(2*n);
        int initial = 0;
        int mid = n;
        
        int i = 0;
        while(mid < 2*n)
        {
            res[i] = nums[initial];
            i++;
            res[i] = nums[mid];

            initial++;
            mid++;
            i = i + 1;    
        }

        return res;
}
};