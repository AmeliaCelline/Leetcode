class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0) return 0;
        
        unordered_map <char, int> hash;
        int left = 0, right = 1;
        hash[s[left]] = 1;
        int maximum = 1;
        
        while (right < len){
            if(hash[s[right]] == 0){
                hash[s[right]]++;
                right++;
            }
        
            else{
                 if (right - left > maximum)
                    maximum= right-left;

                while(s[left] != s[right]){
                    hash[s[left]]--;
                    left++;
                }
                left++;
                right++;
            }
            
        }
        if(len - left  > maximum) maximum = len- left;
        return maximum;
    }
};