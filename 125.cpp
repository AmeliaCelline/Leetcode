class Solution {
public:
    
    bool isPalindrome(string s) {
        //a-z: 97-122 0-9: 48-57
        int len = s.length();
        int temp;
        vector <int> storage;
        for (int i = 0; i < len; i++){
            temp = tolower(s[i]);

            if((temp >= 97 && temp <= 122)|| (temp>=48 && temp<=57)){
                storage.push_back(temp);
            }
        }
        
        int i = 0, j = storage.size()-1;
        while (i < j){
            if (storage[i] != storage[j])return false;
            i++;
            j--;
        }
        return true;
        
        
    
    }
};