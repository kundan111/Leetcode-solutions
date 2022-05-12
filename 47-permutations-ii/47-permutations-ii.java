class Solution {
    List<Integer> resultHolder = new ArrayList<>();
    int numsLen;
    List<List<Integer>> res = new ArrayList<>();
    Set<List<Integer>> resSet = new HashSet<>();

    public List<List<Integer>> permuteUnique(int[] nums) {
        
        this.numsLen = nums.length;
        boolean[] visited = new boolean[nums.length];
        generatePermutation(nums, 0,visited);
        
        return res;
    }
    

    void generatePermutation(int[] nums, int curIndex, boolean[] visited)
    {
        if(resultHolder.size() == numsLen)
        {
            ArrayList<Integer> temp = new ArrayList<>(resultHolder);
            if(!resSet.contains(temp))
            {
                resSet.add(temp);
                res.add(temp);
            }
            return;
        }

        for (int i = 0; i < numsLen; i++) {

            if(!visited[i])
            {
                visited[i] = true;
                resultHolder.add(nums[i]);
                generatePermutation(nums, i, visited);
                resultHolder.remove(resultHolder.size()-1);
                visited[i] = false;

            }

         
        }


    }
}