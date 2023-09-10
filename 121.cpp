class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int temp = prices.back();
        int temp2 = 0;
        for (auto it = prices.end() - 2; it >= prices.begin(); it--){
            //cout << temp << " " << temp2 << " " << max << endl;
            if (temp > temp2 && temp - *it > max){
                max = temp - *it;
            }
            
            else if (temp2 - *it > max) {
                max = temp2 - *it;
            }
            
            
            if (temp > temp2) temp2 = temp;
            temp = *it;
        }
        return max;
    }
};