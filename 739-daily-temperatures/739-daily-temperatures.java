class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        return approach2(temperatures);
    }   


    public int[] approach2(int[] temperatures)
    {
        if(temperatures == null)
        {
            throw new IllegalArgumentException("temperatures can not be null");
        }
        

        Stack<Integer> st = new Stack<>();
        int[] ret = new int[temperatures.length];
        int sz = temperatures.length;

        for (int i = sz-1; i >= 0; i--) {
            while (!st.empty() &&  temperatures[st.peek()] <= temperatures[i]) {
                    st.pop();
            }
            if(st.size() > 0)
            {
                ret[i] = st.peek() - i;
            }else{
                // stack empty
                ret[i] = 0;
            }

            st.push(i);
        }

        
        
        
        return ret;
        
    }
}