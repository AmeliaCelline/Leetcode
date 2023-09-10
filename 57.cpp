class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int current = 0;
        int pos[2] = {-1,-1};
        int secPos[2]= {-1, -1};
        
        for (int i = 0 ; i < intervals.size() ; i++){
            if (newInterval[current] <= intervals[i][1]){
                //cout << newInterval[current] << "test"  << endl;
                pos[current] = i;
                secPos[current] = newInterval[current] < intervals[i][0] ? 0 : 1;
                ++current;
                i-=1;
                if(current == 2) break;
            }
        }
        
        if (pos[0] == -1){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        if (pos[0] != pos[1]){
            if(secPos[0] == 0) intervals[pos[0]][0] = newInterval[0];
            
            if(pos[1] == -1){
                intervals[pos[0]][1] = newInterval[1];
                intervals.erase(intervals.begin() + pos[0] + 1, intervals.end());
                    
            }
            else{
                if (secPos[1] == 0) {
                    intervals[pos[0]][1] = newInterval[1];
                    intervals.erase(intervals.begin() + pos[0] + 1, intervals.begin() + pos[1]);
                }

                else{
                    intervals[pos[0]][1] = intervals[pos[1]][1];
                    intervals.erase(intervals.begin() + pos[0] + 1, intervals.begin() + pos[1] + 1);
                }
            }
    
                
        }
        else{
            if (secPos[0] != secPos[1]){
                intervals[pos[0]][0] = newInterval[0];
            }
            else if (secPos[0] == 0){
                intervals.insert(intervals.begin() + pos[0], newInterval);
            }
        }
        return intervals;
    }
};