// ==================================================
// Problem  :   807 - Max Increase to Keep City Skyline 
// Run time :   0.001 sec
// Language :   Java
// ==================================================

public class Solution {

    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int totalRows = grid.length;
        int totalColumns = grid[0].length;

        int[] topView = new int[totalColumns];
        int[] leftView = new int[totalRows];

        Arrays.fill(topView, 0);
        Arrays.fill(leftView, 0);

        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalColumns; ++j) {
                topView[j] = Math.max(topView[j], grid[i][j]);
                leftView[i] = Math.max(leftView[i], grid[i][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalColumns; ++j) {
                int h = Math.min(topView[j], leftView[i]);
                ans += h - grid[i][j];
            }
        }

        return ans;
    }
}
