class Solution {
    public int maximumWealth(int[][] accounts) {
        
        int row = accounts.length;
        int col = accounts[0].length;

        int maximumWealth = 0;

        for (int i = 0; i < row; i++) {
                int cur = 0;
                for (int j = 0; j < col; j++) {
                    cur += accounts[i][j];
                }
                maximumWealth = Math.max(cur, maximumWealth);
        }
        
        return maximumWealth;
    }
}