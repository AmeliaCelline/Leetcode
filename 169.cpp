class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, current;
        
        for (auto it = nums.begin(); it!= nums.end(); it++){
            if (counter == 0){
                current = *it;
                ++counter;
            }
            else{
                if (*it == current) ++counter;
                else --counter;
            }
        }
        return current;
        
    }
};