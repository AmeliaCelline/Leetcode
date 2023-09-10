class Solution {
public:
    
    int recursion(int n, vector<int> & dp){
        if (n < 0) return 0;
        else if (dp[n] != 0) return dp[n];
        else if (n==1 || n==0) return 1;
        
        dp[n] = (recursion(n-1,dp) + recursion(n-2,dp));
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        return (recursion(n-1, dp) + recursion(n-2,dp));
    }
};