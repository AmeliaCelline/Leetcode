class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        map <int, int> hash;

        for (int i = 0; i < nums.size(); i++){
            hash[nums[i]]++;
        }
        
        int remainder = 0;
        int temp;
        for (auto it = hash.begin(); it!= hash.end(); it++){
            --(it->second);
            remainder -= it->first;
            for (auto it2 = it; it2 != hash.end(); it2++){
                
                if (it2->second == 0) continue;
                //cout << it->first << " " << it2->first << " " << remainder << endl;
                it2->second--;
                temp = remainder-it2->first;
                if (temp > it2->first || hash.find(temp) == hash.end() || hash[temp] <= 0){
                    it2->second++;
                    continue;
                }
                vector<int>temp{it->first, it2->first, (remainder-it2->first)};
                answer.push_back(temp);
                it2->second++;

            }
            remainder = 0;
            it->second = 0;
        }
        return answer;
        
    }
};