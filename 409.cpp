class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char, int> hash;
        for (char c : s){
            if(hash.count(c) != 0) ++hash[c];
            else hash[c] = 1;
        }
        
        bool odd = false;
        int len = 0;
        for (auto i : hash){
            if (i.second % 2 == 0) len += i.second;
            else{
                len += i.second-1;
                odd= true;
            }
        }
        if (odd) len +=1;
        return len;
    }
};