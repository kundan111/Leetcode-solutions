class Solution {
    public List<List<Integer>> permute(int[] nums) {
        
        List<List<Integer>> ans = new ArrayList<>();
        
        int l = 0;
        int r = nums.length;

        
        generatePermutations(ans,nums, l, r);
     
        return ans;
    }

    void generatePermutations(List<List<Integer>> ans,int[] nums, int l, int r)
    {
        
        if(l == r)
        {
            ans.add(Arrays.stream(nums).boxed().toList());
            return;
        }

        for (int i = l; i < r; i++) {
            swap(nums, l, i);
            generatePermutations(ans,nums, l+1, r);
            swap(nums, l, i);
        }

        
    }

    void swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}