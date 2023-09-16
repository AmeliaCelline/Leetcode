class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector <int> hash(n+1, 1);
        vector<int>answer;
        for (auto i : nums){
            hash[i] = 0;
        }
        for (int i = 1; i <=n ; i++){
            if (hash[i] == 1) answer.push_back(i);
        }
        return answer;
        //time: O(n)
        //space: O(n)

    }

};