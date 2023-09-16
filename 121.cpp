class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0; //maxprofit
        int minPrice = INT_MAX; //the minimum price up to day i 
        for (auto i : prices){
            minPrice = i < minPrice ? i : minPrice;
            max = (i-minPrice)  > max ? (i-minPrice) : max; 
        }


        return max;
    }
};