class Solution {
public:

    int * root;
    int find_root(int x){
        //if the root node still point to itself, just directly return itself.
        if(root[x] == x) return x;
        //if nope, do recursive i guess till u find the root node
        return find_root(root[x]);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //store the root node for each set
        root = new int[accounts.size()];
        
        //the key is the email, the value is the root node
        unordered_map<string,int>email_root;
        for (int i = 0; i < accounts.size(); i++){
            root[i] = i;
            for (int j = 1; j < accounts[i].size(); j++){
                //still havent been found before this
                if(email_root.find(accounts[i][j]) == email_root.end()){
                    email_root[accounts[i][j]] = i;
                }
                //already been found before, so make one of the root node point to the other root node
                else{
                    int set1 = find_root(email_root[accounts[i][j]]);
                    int set2 = find_root(i);
                    if (set1 != set2){
                        root[set1] = root[set2];
                    }
                }
            }
        }

        //clean up, so no root nodes anymore
        vector<vector<string>>clean(accounts.size(), vector<string>());
        int counter = 0;
        for (auto &i : email_root){
            int cur_root = find_root(i.second);
            if(clean[cur_root].empty()){
                clean[cur_root].push_back(accounts[cur_root][0]);
                counter +=1;
            }
            clean[cur_root].push_back(i.first);
        }
        vector<vector<string>>answer(counter, vector<string>());
        counter = 0;
        for (auto &i : clean){
            if(!i.empty()){
                sort(i.begin()+1, i.end());
                for (auto &j : i){           
                    answer[counter].push_back(j);
                }
                counter+=1;   
            }
        }

        return answer;
    }
};
