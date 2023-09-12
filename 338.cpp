class Solution {
public:
    vector<int> countBits(int n) {
        //O(n), DP
        vector <int> dp(n+1, 0);
        dp[0] = 0;
        for (int i = 1 ; i <= n ; i++){
            dp[i] = (i%2) + dp[i/2]; 
        }
        return dp;

        /*
        O(n log n)
        vector <int> answer(n+1, 0);
        for (int i = 0; i <=n; i++){
            int copy = i;
            while(copy != 0){
                if (copy % 2 ==1){
                    answer[i] += 1;
                }
                copy /= 2; 
            }
        }

        return answer;
        */
    }
};