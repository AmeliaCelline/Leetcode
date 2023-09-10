class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums){
            sum+=i;
        }

        if (sum % 2 == 0){
            sum /= 2;
        }
        else{
            return false;
        }

        bool * dp = new bool[sum+1];
        fill_n(dp, sum+1, 0);

        dp[0] = 1;

        //formula b[i-1][w] || b[i-1][w-wi]
        //one row approach

        for (auto i : nums){
            for (int w = sum; w > 0; w--){
                    if(w-i >= 0){
                        dp[w] = dp[w] | dp[w-i];
                    }
            }
        }

        return dp[sum];
    }
};