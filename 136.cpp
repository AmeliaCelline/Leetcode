class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //30001 because the constraint is just -3x10^4 <= nums[i] <= 3x10^4
        int ans = 30001;
        for (auto i : nums){
            ans ^= i;
        }
        ans ^= 30001;
        return ans;
    }
};