class Solution {
    public int trap(int[] height) {

        int answer = 0;
        
        for (int i = 0; i < height.length; i++) {
            int left_max = height[i];
            int right_max = height[i];

            for (int j = 0; j < i; j++) {
                left_max = Math.max(height[j], left_max);
            }

            for (int k = i+1; k < height.length; k++) {
                right_max = Math.max(height[k], right_max);
            }

            answer += Math.min(left_max, right_max) - height[i];
            
        }
     
        return answer;
        
    }
}