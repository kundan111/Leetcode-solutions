class FinalNodeAndWeightPair{
    
    String finalNode;
    double weight;

    public FinalNodeAndWeightPair(String finalNode, double weight) {
        this.finalNode = finalNode;
        this.weight = weight;
    }

    @Override
    public String toString() {
        return "{" + finalNode + "," + weight + "}";
    }

}
class Solution {
    double ans;

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        
        HashMap<String,List<FinalNodeAndWeightPair>> hm = new HashMap<>();

        int curIndex = 0;
        for (List<String> list : equations) {
            String start = list.get(0);
            String end = list.get(1);

            
            if(hm.containsKey(start))
            {
                List<FinalNodeAndWeightPair> val = hm.get(start);
                val.add(new FinalNodeAndWeightPair(end, values[curIndex]));
                hm.put(start, val);
            }else{
                
                List<FinalNodeAndWeightPair> lst = new ArrayList<>();
                lst.add(new FinalNodeAndWeightPair(end, values[curIndex]));
                hm.put(start, lst);
            }

            if(hm.containsKey(end))
            {
                List<FinalNodeAndWeightPair> val = hm.get(end);
                val.add(new FinalNodeAndWeightPair(start, 1/values[curIndex]));
                hm.put(end, val);
            }else{
                
                List<FinalNodeAndWeightPair> lst = new ArrayList<>();
                lst.add(new FinalNodeAndWeightPair(start, 1/values[curIndex]));
                hm.put(end, lst);
            }

            curIndex++;
        }
        



        double[] res = new double[queries.size()];

        int resIndex = 0;

        for (List<String> list : queries) {
            String start = list.get(0);
            String end = list.get(1);

            if(!hm.containsKey(start) || !hm.containsKey(end))
            {
                res[resIndex] = -1.0;
            }else{
                if(start.equals(end))
                {
                    res[resIndex] = 1.0;
                }else{
                    Set<String> st = new HashSet<>();
                    boolean dfs = dfs(start, end,hm, 1.0,st);
                    if(dfs)
                    {
                        res[resIndex] = ans;
                    }else{
                        res[resIndex] = -1.0;
                    }
                    ans = -1.0;
                }
            }
            resIndex++;
        }
        
        

        return res;
    }
    

    boolean dfs(String startingNode, String endingNode, HashMap<String,List<FinalNodeAndWeightPair>> hm, double curProd, Set<String> visited)
    {
        if(visited.contains(startingNode))
        {
            return false;
        }

        if(endingNode.equals(startingNode))
        {
            ans = curProd;
            return true;
        }

        visited.add(startingNode);

        boolean ans = false;
        for (FinalNodeAndWeightPair finalNodeAndWeightPair : hm.get(startingNode)) {
                ans = ans || dfs(finalNodeAndWeightPair.finalNode, endingNode, hm, curProd*finalNodeAndWeightPair.weight, visited);

        }


        return ans;

    }
}