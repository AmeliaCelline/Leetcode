class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //0 ms runtime
        int counter_s = 0, counter_t = 0;
        int index_s = s.length()-1, index_t = t.length()-1;
        char cur_s, cur_t;

        //how the algo works
        //ab#c amd ad#c
        //c, c true
        //counter_s +=1 , counter_t +=1
        //skip b and d
        //a, a true

        //a#b, b
        //b, b true
        //# counter_s +=1, ""
        //skip a, "" 
        //"", ""

        while (index_s >=0 || index_t >=0){
            bool temp = false;
            if((index_s >= 0 && s[index_s] == '#')){
                counter_s +=1;
                index_s -=1;
                temp = true;
            }
            if (index_t >=0 && t[index_t] == '#' ){
                counter_t +=1;
                index_t-=1;
                temp = true;
            }

            if (temp) continue;

            temp = false;
            if(counter_s > 0){
                index_s -= 1; 
                counter_s -= 1;
                temp = true;
            }
            if(counter_t > 0){
                index_t -= 1;
                counter_t -=1;
                temp=  true;
            }
            if (temp) continue;

            
            cur_s = index_s >= 0 ? s[index_s] : '+';
            cur_t = index_t >= 0 ? t[index_t] : '+';

            index_s -=1;
            index_t -=1;

            if(cur_s != cur_t) return false;
        }

        return true;

    }
};