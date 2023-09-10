class Solution {
public:

    int uniquePaths(int m, int n) {
        //me trying to redo it using one row
        int dp[n];
        for (int i = 0 ; i < n; i++){
            dp[i]= 1;
        }

        //m = no of rows, n = no of column
        for(int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[j] = dp[j-1] + dp[j];
            }
        }

        return dp[n-1];

    }
};