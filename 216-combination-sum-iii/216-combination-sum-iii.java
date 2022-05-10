class Solution {
    HashSet<List<Integer>> res = new HashSet<>();
    HashSet<Integer> hs = new HashSet<>();
    List<Integer> temp = new ArrayList<>();

    public List<List<Integer>> combinationSum3(int k, int n) {
        
        recur(n, k);
        return new ArrayList<>(res);
    }
    
    void recur(int remainingSum,int remainingK)
    {
        // System.out.println("recur(" + remainingSum + "," + remainingK + "," + temp + ");");
        if(remainingSum < 0 || remainingK < 0)
        {
            return;
        }

        if(remainingSum == 0 && remainingK == 0)
        {
            List<Integer> al = new ArrayList<>(temp);
            Collections.sort(al);
            res.add(al);
            return;
        }
        if(remainingSum == 0 || remainingK == 0)
        {
            return;
        }

        for (int curSum = 1; curSum <= 9; curSum++) {
            if(remainingSum >= curSum && !hs.contains(curSum))
            {
                temp.add((Integer)curSum);
                hs.add(curSum);
                recur(remainingSum-curSum ,remainingK - 1);
                hs.remove(curSum);
                temp.remove((Integer)curSum);
            }
        }
        

    }
}