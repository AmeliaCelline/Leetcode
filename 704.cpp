class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = nums.size();
        
        int l = 0, r = nums.size() - 1;
        int middle;
        while (i > 0){
            i = i/2;
            
            middle = (r+l)/2;
            if(nums[middle] == target)return middle;
            else if (nums[middle] < target) l = middle+1;
            else r = middle-1;
        }
        return -1;
    }
};