class Solution {
    public int findUnsortedSubarray(int[] nums) {
        
        return approach2(nums);

    }
    

    public int approach2(int[] nums) 
    {
        // use cooncept of next greater element to find the first out of order element
        // from left side and first out of order element from right side and then take
        // difference of their indexes

        Stack<Integer> st = new Stack<>();
        int start = nums.length;
        int end = 0;
        for (int i = 0; i < nums.length; i++) {
            
            int curEle = nums[i];
            while (!st.empty() && nums[st.peek()] > curEle) {
                start = Math.min(st.pop(), start);
            }

            st.push(i);
        }

        if(start == nums.length)
        {
            return 0;
        }

        st.clear();

        for (int i = nums.length-1; i >= 0; i--) {
            
            int curEle = nums[i];
            while (!st.empty() && nums[st.peek()] < curEle) {
                end = Math.max(st.pop(), end);
            }

            st.push(i);
        }

        
        return end - start + 1;

    }
}