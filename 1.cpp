class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> remainder;
        int temp;
        vector <int> answer;
        
        for (auto i = nums.begin(); i < nums.end(); ++i){
            
            for (auto j = remainder.begin(); j < remainder.end(); j++){
                if (*i == *j){
                    answer.push_back(j - remainder.begin());
                    answer.push_back(i - nums.begin());
                    return answer;
                }
            }
            
            remainder.push_back(target - *i);
            
        }
        return answer;
    }
};