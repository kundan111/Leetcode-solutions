class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        vector<int> unique_array;

        int i = 0;
        int uniq_count = 0;

        if(sz > 0)
        {
            unique_array.push_back(nums[0]);
        }

        while(i < sz)
        {
            // pick the cur element
            int cur = nums[i];

            //now check its occurence again in further indexes
            int j = i;
            while(j < sz)
            {
                if(cur == nums[j])
                {
                    j++;
                }else{
                    unique_array.push_back(nums[j]);
                    break;
                }
            }

            uniq_count += 1;

            i = j;

        }

        for(int i = 0; i < uniq_count; i++)
        {
            nums[i] = unique_array[i];
        }
        
        return uniq_count;
            
    }
};