class Solution {
    public List<String> generateParenthesis(int n) {
        int close = n;
        int open = n-1;
        List<String> result = new ArrayList<>();
        collectBalancedParanthesis(result, open, close, "(");
        return result;
    }
    public void collectBalancedParanthesis(List<String> result, int open, int close, String cur)
    {
        if(open == 0 && close == 0)
        {
            result.add(cur);
        }

        if(open > 0)
        {
            
            collectBalancedParanthesis(result, open-1, close, cur + "(");
        }

        if(close > open)
        {
            
            collectBalancedParanthesis(result, open, close-1, cur + ")");

        }

    }
}