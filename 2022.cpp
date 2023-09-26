class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>answer;
        if(original.size() != (m*n)) return answer;
        else{
            answer.resize(m, vector<int>(n));
            int counter = 0;
            for(int i = 0; i < m; i++){
                for (int j = 0 ; j<n; j++){
                    answer[i][j] = original[counter];
                    counter += 1;
                }
            }

            return answer;
        }
    }
};