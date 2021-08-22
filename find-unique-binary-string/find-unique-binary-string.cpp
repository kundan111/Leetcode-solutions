class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ret = "";
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            ret += nums[i][i] == '0' ? '1' : '0';
        }
        return ret;
    }
    
};