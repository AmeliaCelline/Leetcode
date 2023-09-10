class Solution {
public:
    vector< vector<int> > dp;
    int max = 1;
    int max_left = 0;
    
    string temp;
    void div(int left, int right, int len){
        //cout << left << " first time " << right << endl;
        if (len == 1){
            dp[left][right] = 1;
            return;
        }
        else if (len == 2){
            if (temp[left] == temp[right]){
                //cout << "itgoeshere" << endl;
                dp[left][right] = 1;
                if (max < 2) {
                    max = 2;
                    max_left = left;
                }
            }
            else dp[left][right] = 2;
            
            return;
        }
        
        if (dp[left+1][right] == 0)
            div(left+1, right, len-1);
        
        if (dp[left+1][right-1] == 0)
            div(left+1, right-1, len-2);
        
        if (dp[left][right-1] == 0)
            div(left, right-1, len-1);
        
        
        if(dp[left+1][right-1] == 1 && temp[left] == temp[right]){

            //cout << left << " 1 " << right << endl;
            dp[left][right] = 1;
            if (len>max) {
                max = len;
                max_left = left;
            }
        }
        else{
            dp[left][right] = 2;
        }
           
            
    }
    string longestPalindrome(string s) {
        int len = s.length();
        temp = s;
        for (int i = 0 ; i < len; i++){
            dp.push_back(vector<int>(len));
        }
        div(0, len-1, len);
        
        string answer = s.substr(max_left, max);
        return answer;
        
        
    }
};