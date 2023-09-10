class Solution {
public:
    bool isValid(string s) {
        unordered_map <char, int> storage;
        storage['('] = 1;
        storage[')'] = 2;
        storage['['] = 5;
        storage[']'] = 6;
        storage['{'] = 8;
        storage['}'] = 9;
        
        vector <int> temp;
        for (int i = 0; i < s.length(); i++){
            if (temp.empty()) temp.push_back(storage[s[i]]);
            else{
                if (temp.back() + 1 == storage[s[i]]){
                    temp.pop_back();
                }
                else{
                    temp.push_back(storage[s[i]]);
                }
            }
        }
        
        return temp.empty();
    }
};