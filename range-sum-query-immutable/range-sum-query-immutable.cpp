class NumArray {
private:
    vector<int>vec;
    vector<int>cul;
public:
    NumArray(vector<int>& nums) {
        vec = nums;
        cul.push_back(0);
        int prev = 0;
        for(int val : nums)
        {
            cul.push_back(prev+val);
            prev = prev+val;
        }
    }
    
    int sumRange(int l, int r) {
        
        return cul[r+1] - cul[l];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */