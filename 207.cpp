class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //search for no cycle
        if(prerequisites.size() == 0) return true;
        int n = numCourses;
        //make adjacency list first
        vector< vector<int> > edges(n);

        for (auto &i : prerequisites){
            edges[i[1]].push_back(i[0]);
        }

        vector<int>visited(n, 0); //0 is not visited, 1 is visited
        vector<int>in_stack(n , 0);

        //do dfs to check for the finish time
        stack<int>for_dfs;

        for (int i = 0 ; i <n ; i++){
            if(visited[i] == 0){
                for_dfs.push(i);
                in_stack[i] = 1;
            }

            while(!for_dfs.empty()){
                int cur = for_dfs.top();
                visited[cur] = 1;
                in_stack[cur]= 1;
                
                //all neighbors have been transversed
                if(edges[cur].size() == 0 ){
                    for_dfs.pop();
                    in_stack[cur] = 0;
                }
                else{
                    if (visited[edges[cur].back()] == 0){ //not yet visited, push to stack
                        for_dfs.push(edges[cur].back());
                    }

                    if (in_stack[edges[cur].back()] == 1) return false;

                    edges[cur].erase(edges[cur].end()-1);	
                }
                
            }
        }

        return true;



    }
};

//other solution
/*
kahn algo
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <vector<int>> graph(numCourses, vector<int>());
        vector <int> indegree(numCourses, 0);

        for (auto &i : prerequisites){
            graph[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        stack<int>zero_deg;
        for(int i = 0 ; i < numCourses; i++){
            if(indegree[i] == 0){
                zero_deg.push(i);
            } 
        }

        while(!zero_deg.empty()){
            int cur = zero_deg.top();
            zero_deg.pop();
            numCourses--;
            //transversing through the neighbors
            for (auto &i : graph[cur]){
                indegree[i]--;
                if(indegree[i] == 0)
                    zero_deg.push(i);
            }
        }
        
        //if no vertex remain in the graph, then it is possible to make a schedule
        return numCourses == 0 ? true : false;


    }
};

*/