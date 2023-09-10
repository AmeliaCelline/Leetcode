class Solution {
public:
    double ** distance;
    void sift_down(int i, int size){

        while(2*i+1 < size ){
    
            if(2*i+2 < size && distance[2*i+2][0] < distance[2*i+1][0]){
                if (distance[i][0] > distance[2*i+2][0]){
                    swap(distance[i], distance[2*i+2]);
                    i = 2*i+2;
                    continue;
                }
            }
            else{
                if (distance[i][0] > distance[2*i+1][0]){
                    swap(distance[i], distance[2*i+1]);
                    i = 2*i+1;
                    continue;
                }
            }
            break;
                
        }
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        distance = new double*[points.size()];
        vector<vector<int>> answer(k);
        
        //constructing heap
        for (int i = points.size()-1 ; i >=0; i--){
            distance[i] = new double[2];
            distance[i][0] = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            distance[i][1] = i;
            sift_down(i, points.size());
        }
        
        //take the min k times
        int last_pointer = points.size()-1;
        for (int i = 0; i < k; i++){
            answer[i].push_back(points[distance[0][1]][0]);
            answer[i].push_back(points[distance[0][1]][1]);
            
            swap(distance[0], distance[last_pointer]);

            --last_pointer;
            sift_down(0, last_pointer+1);
            
            
        }

        
        return answer;
    }
};