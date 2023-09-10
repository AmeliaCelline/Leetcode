// first solution that i came up with

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>rotten;
        //min 0, find all the rotten ones

        int counter = 0;
        int cur_rotten = 0;
        int next_rotten = 0;
        int min = 0;

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    counter += 1;
                }

                if(grid[i][j] == 2){
                    pair<int, int> temp(i, j);
                    rotten.push(temp);
                    cur_rotten += 1;
                }
            }
        }

        counter -= cur_rotten;

        while(counter > 0){
            while(cur_rotten > 0){
                pair<int,int>cur_fruit = rotten.front();
                int i = cur_fruit.first, j = cur_fruit.second;
                rotten.pop();

                if (i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2; 
                    pair<int,int>temp(i-1,j);
                    rotten.push(temp);
                    next_rotten++;
                }
                
                if (i+1 < m && grid[i+1][j] == 1){
                    grid[i+1][j] = 2; 
                    pair<int,int>temp(i+1,j);
                    rotten.push(temp);
                    next_rotten++;
                }
                
                if (j-1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2; 
                    pair<int,int>temp(i,j-1);
                    rotten.push(temp);
                    next_rotten++;
                }
                
                if (j+1 < n && grid[i][j+1] == 1){
                    grid[i][j+1] = 2; 
                    pair<int,int>temp(i,j+1);
                    rotten.push(temp);
                    next_rotten++;
                }

                cur_rotten--; 
            }

            min += 1;
            counter -= next_rotten;
            cur_rotten = next_rotten;
            if (next_rotten == 0) return -1;
            next_rotten = 0;

        }
        
        return min;



    }
};