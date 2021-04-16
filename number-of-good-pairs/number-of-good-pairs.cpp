class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
    vector<int> res(101);
    int i = 0;
    int sz = nums.size();
    int result = 0;
    while( i < sz)
    {
        res[nums[i]]++;
        i++;
    }

    i = 0;
    while(i < 101)
    {
        if(res[i] > 1)
        {
            int temp = res[i];
            result = result + temp*(temp-1)/2;
        }
        
        i++;
    }

    return result;
        
}
};