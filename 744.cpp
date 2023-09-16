class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        while (r >= l){
            int mid  = (r+l)/2;
            if (letters[mid] <= target){
                l = mid+1;
            }  
            else{
                if(mid == 0) return letters[0];
                else if (letters[mid-1] <= target) return letters[mid];
                else r = mid-1;
            }

        }
        return letters[0];

    }
};