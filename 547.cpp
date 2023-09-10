class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector <int> disjoint(n, -1);
        
        int root_i, root_j;
        int temp, temp2;
        for (int i = 1 ; i < n ; i++){
            for (int j = 0 ; j < i; j++){
                if (isConnected[i][j] == 1){
                    
                    root_i = disjoint[i] == -1 ? i : disjoint[i];
                    root_j = j;
                    while(disjoint[root_j] != -1){
                        temp = root_j;
                        root_j = disjoint[root_j];
                        disjoint[temp] = root_i;
                    }
                    if (root_i != root_j)
                        disjoint[root_j] = root_i;
                    
                }   
            }
        }
        
        int answer = 0;
        
        for (int i = 0; i < n ; i++){
            if (disjoint[i] == -1) {
                //cout << i << endl;
                answer += 1;
            }
        }
        return answer;
    }
};