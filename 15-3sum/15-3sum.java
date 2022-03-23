class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length < 3)
        {
            return res;
        }


        // NLog(N)
        Arrays.sort(nums);

        int sz = nums.length;
        for (int i = 0; i < sz-2; i++) {

            if(i == 0 || nums[i] != nums[i-1])
            {
                int target = 0-nums[i];
                int l = i+1;
                int r = sz-1;

                while (l < r) {
                    if(nums[l] + nums[r] == target)
                    {
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[l]);
                        temp.add(nums[r]);
                        temp.add(nums[i]);
                        res.add(temp);
                        
                        int tempLeft = nums[l];
                        int tempRight = nums[r];

                        while(l < r && nums[l] == tempLeft && nums[r] == tempRight)
                        {
                            l++;
                            r--;
                        }

                    }else if(nums[l] + nums[r] > target)
                    {
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }

        return res;   
    }
}