class RandomizedSet {
    vector<int> arr;
    unordered_map<int, int> hash;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.find(val) != hash.end()) {
            return false;
        }
        hash[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = hash.find(val);
        if (it == hash.end()) {
            return false;
        }
        swap(arr[it->second], arr.back());
        arr.pop_back();
        hash[arr[it->second]] = it->second;
        hash.erase(it);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (arr.empty()) return -1;
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */