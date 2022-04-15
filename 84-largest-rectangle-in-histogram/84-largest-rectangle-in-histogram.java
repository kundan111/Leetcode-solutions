class Solution {
    public int largestRectangleArea(int[] heights) {
        return approach2(heights);
    }
    
    
    public int approach2(int[] arr) {
        

        int[] toTheRightSmaller = new int[arr.length];
        int sz = arr.length;
        Stack<Integer> st = new Stack<>();

        for (int i = sz-1; i >= 0; i--) {
            
            int curEle = arr[i];

            while (!st.empty() && arr[st.peek()] >= curEle) {
                st.pop();
            }

            if(st.empty())
            {
                toTheRightSmaller[i] = sz;
            }else{
                toTheRightSmaller[i] = st.peek();
            }
            st.push(i);

        }

        // System.out.println(Arrays.toString(toTheRightSmaller));

        st.clear();

        int[] toTheLeftSmaller = new int[arr.length];
        for (int i = 0; i < sz; i++) {
            
            int curEle = arr[i];

            while (!st.empty() && arr[st.peek()] >= curEle) {
                st.pop();
            }

            if(st.empty())
            {
                toTheLeftSmaller[i] = -1;
            }else{
                toTheLeftSmaller[i] = st.peek();
            }
            st.push(i);

        }

        // System.out.println(Arrays.toString(toTheLeftSmaller));

        int maxArea = 0;

        for (int i = 0; i < toTheLeftSmaller.length; i++) {
            maxArea = Math.max(maxArea, ((toTheRightSmaller[i]-1) - (toTheLeftSmaller[i]+1) + 1)*arr[i]);
        }

        
        return maxArea;
    }
}