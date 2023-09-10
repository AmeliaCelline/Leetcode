//is inefficient i guess and messy, so see notes for
//better solution i guess
class Solution {
public:
    string addBinary(string a, string b) {
        
        if (a.length() < b.length()){
            string temp(b.length() - a.length(), '0');
            a = temp + a;
        }
        else if (b.length() < a.length()){
            string temp(a.length() - b.length(), '0');
            b = temp + b;
        }
        
        int extra = 0;
        int temp;
        
        string answer = "";
        
        for (int i = 0; i < a.length(); i++){
            temp = (a[a.length() - i - 1] - '0' ) + (b[b.length() - i - 1]-'0') + extra;
            if (temp > 1) {
                extra = temp/2;
                temp %= 2;
            }
            else extra = 0;
            
            answer = to_string(temp) + answer;
        }
        
        
        if(extra > 0) answer = '1' + answer;
        return answer;
    }
};