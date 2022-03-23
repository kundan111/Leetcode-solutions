class Solution {
    private List<List<Integer>> newRes = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        int sz = nums.length;
        ArrayList<Integer> temp = new ArrayList<>();
        recur(nums, 0, sz, temp);
     
        return newRes;
    }
    void recur(int[] nums, int cur, int sz, ArrayList<Integer> temp)
    {
       if(cur == sz)
       {
           newRes.add(temp.stream().collect(Collectors.toList()));
            return;   
       }
       temp.add(nums[cur]);
       recur(nums, cur+1, sz, temp);
       temp.remove(temp.size()-1);
       recur(nums, cur+1, sz, temp);
    }
}