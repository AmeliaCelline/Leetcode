class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int temp[26] = {0};
        
        for (int i = 0; i < magazine.length();i++){
            temp[int(magazine[i] - 'a')]++;
        }
        for (int i = 0 ; i < ransomNote.length(); i++){
            temp[int(ransomNote[i] - 'a')]--;
        }
        for (int i = 0; i < 26; i++){
            if (temp[i] <0)return false;
        
        }
        return true;
    }
};