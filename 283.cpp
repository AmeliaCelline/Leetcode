class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroPointer = 1, zeroPointer = 0;
        while(nonZeroPointer < nums.size()){
            //find the non zero element
            while(nonZeroPointer < nums.size() && nums[nonZeroPointer] == 0 ){
                nonZeroPointer += 1;
            }

            if(nonZeroPointer == nums.size()) break;
            //find the zero element
            while(zeroPointer < nonZeroPointer && nums[zeroPointer] != 0 ){
                zeroPointer += 1;
            }

            swap(nums[zeroPointer], nums[nonZeroPointer]);
            zeroPointer += 1;
            nonZeroPointer += 1;

        }
    }
};