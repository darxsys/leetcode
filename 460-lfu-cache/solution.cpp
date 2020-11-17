class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (capacity_ <= 0) return -1;
        
        auto it = keyToLevel_.find(key);
        if (it != keyToLevel_.end()) {
            auto elem = keyToPos_[key];
            
            promoteKey(key);
            return elem->second;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity_ <= 0) return;
        
        auto it = keyToLevel_.find(key);
        if (it != keyToLevel_.end()) {
            promoteKey(key);
            keyToPos_[key]->second = value;
        } else {
            if (keyToLevel_.size() >=  capacity_) {
                auto& cache = levelToLRU_[minCount_];
                auto elem = cache.back();
                cache.pop_back();
                
                keyToLevel_.erase(elem.first);
                keyToPos_.erase(elem.first);
            }
            
            minCount_ = 1;
            if (levelToLRU_.find(1) == levelToLRU_.end()) {
                levelToLRU_.emplace(1, list<pair<int, int>>());
            }
            
            levelToLRU_[1].push_front({key, value});
            keyToLevel_.emplace(key, 1);
            keyToPos_.emplace(key, levelToLRU_[1].begin());
            
        }
        
        
    }
    
private:
    void promoteKey(int key) {
        auto it = keyToLevel_.find(key);
        auto level = it->second;
        auto& cache = levelToLRU_[level];


        auto nextLevel = levelToLRU_.find(level+1);
        if (nextLevel == levelToLRU_.end()) {
            levelToLRU_.emplace(level+1, list<pair<int, int>>());
        }

        nextLevel = levelToLRU_.find(level+1);
        nextLevel->second.splice(nextLevel->second.begin(), 
                                 cache, keyToPos_[key]);

        keyToLevel_[key]++;
        keyToPos_[key] = nextLevel->second.begin();

        if (cache.empty() && minCount_ == level) {
            minCount_++;    
        }        
    }
    
    int capacity_ = 0;
    int minCount_ = 1;
    unordered_map<int, list<pair<int, int>>> levelToLRU_;
    unordered_map<int, int> keyToLevel_;
    unordered_map<int, list<pair<int, int>>::iterator> keyToPos_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */