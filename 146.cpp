class LRUCache {
public:
    int size;
    unordered_map <int, list<pair<int,int>>::iterator> hash;
    list <pair<int, int>> linked;
    
    LRUCache(int capacity){
        size = capacity;
    }
    
    
    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end()) return -1;
        
        linked.splice(linked.begin(), linked, it -> second);
        return it ->second ->second;
        
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end()){
            linked.splice(linked.begin(), linked, it->second);
            it->second ->second= value;
        }
        else{        
            if(hash.size() == size){
                hash.erase(linked.back().first);
                linked.pop_back();
            }

            linked.push_front(make_pair(key,value));
            hash[key] = linked.begin();

        }
            
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */