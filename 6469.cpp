class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map <int, int> hash;
        
        for (auto i : nums){
            hash[i] = 1;
        }
        
        for (int i = 0 ; i < moveFrom.size(); i++){
            if (hash.find(moveFrom[i]) != hash.end()){
                hash.erase(moveFrom[i]);
                hash[moveTo[i]] = 1;
            }
        }
        
        vector<int>temp;
        for (auto i : hash){
            temp.push_back(i.first);
        }
        sort(temp.begin(), temp.end());
        return temp;
    }
};

/*
someone's else code
dangg how can I not think of just hashing the moveFrom rip me
class Solution:
    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        occupied = {n: True for n in nums}
        for i in range(len(moveFrom)):
            del occupied[moveFrom[i]]
            occupied[moveTo[i]] = True
        return sorted(occupied.keys())

*/