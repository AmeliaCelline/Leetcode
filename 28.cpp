class Solution {
public:
    int strStr(string haystack, string needle) {
        //creating prefix table
        int needle_len = needle.length();
        vector<int> p(needle_len);
        
        p[0] = -1;
        int temp = -1;
        for (int i = 1; i < needle_len; i++){
            while (temp >= 0 && needle[temp+1] != needle[i]){
                temp = p[temp];
            }
            if (needle[temp+1] == needle[i]){
                temp += 1;
            }
            
            p[i]  = temp;
        }
        
        
        int i = 0, j = 0;        
        int answer = -1;
        while (i < haystack.length()){
            //cout << i << " " << j << " " << p[j] << endl;
            if (haystack[i] == needle[j]){
                j += 1;
                
                if (j == needle_len){
                    answer = i-needle_len+1;
                    break;
                }
                i+=1;
            }
            else if (j==0)i+=1;
            else{

                j = p[j-1]+1;
            }
            
        }
        return answer;
    }
};