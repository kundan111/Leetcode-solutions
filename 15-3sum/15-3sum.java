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
        Set<List<Integer>> st = new HashSet<>();
        for (int i = 0; i < sz; i++) {
            int target = 0-nums[i];
            int l = i+1;
            int r = sz-1;

            // System.out.println("target: " + target);
            while (l < r) {
                if(nums[l] + nums[r] == target)
                {
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[l]);
                    temp.add(nums[r]);
                    temp.add(nums[i]);
                    st.add(temp);
                    // System.out.println("printing temp: " + temp);
                    l++;
                    r--;
                }else if(nums[l] + nums[r] > target)
                {
                    r--;
                }else{
                    l++;
                }
            }
        }

        for (List<Integer> list : st) {
            res.add(list);
        }
        
        
        return res;
    }
}