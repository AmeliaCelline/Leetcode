class Solution {
public:

    bool isAnagram(string s, string t) {
        // t-> s
        int temp[26] = {0};
        int temp2[26]= {0};
        if(s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++){
            //cout << int(s[i] - 'a') << " " << int(t[i] - 'a') << endl; 
            temp[int(s[i] - 'a')]++;
            temp2[int(t[i] - 'a')]++;
        }
        
        for (int i = 0 ; i < 26 ; i++){
            if (temp[i] != temp2[i])return false;
        }
        return true;
        
    }
};