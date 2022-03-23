class Solution {
    public int trap(int[] height) {
        int answer = 0;
        int[] left_max = new int[height.length];
        int[] right_max = new int[height.length];

        left_max[0] = height[0];
        right_max[height.length-1] = height[height.length-1];

        int leftMaxSoFar = height[0];
        for (int i = 1; i < right_max.length; i++) {
            leftMaxSoFar = Math.max(leftMaxSoFar, height[i]);
            left_max[i] = leftMaxSoFar;
        }

        int rightMaxSoFar = height[height.length-1];
        for (int i = height.length-2; i >= 0; i--) {
            rightMaxSoFar = Math.max(rightMaxSoFar, height[i]);
            right_max[i] = rightMaxSoFar;
        }

        
        for (int i = 0; i < height.length; i++) {
            answer += Math.min(left_max[i], right_max[i]) - height[i];
        }

        return answer;
    }
}