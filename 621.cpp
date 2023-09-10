class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int highest = 0;
        unordered_map <char, int> hash;
        
        for (auto i :tasks){
            hash[i]++;
            highest = hash[i] > highest ? hash[i] : highest;
        }
        
        int answer = (highest-1) * (n+1);
        int extra = 0;
        for (auto i: hash){
            if (i.second == highest){
                answer += 1;
                if (extra == n + 1) break;
            }
        }
        
        answer = tasks.size() > answer ? tasks.size() : answer;
        return answer;
    }
};