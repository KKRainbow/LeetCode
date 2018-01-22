class MapSum {
    struct TrieNode {
        map<char, TrieNode*> children;
        TrieNode* parent;
        int sum, val;
    } *root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        auto step = root;
        for (auto c: key) {
            auto it = step->children.find(c);
            if (it == step->children.end()) {
                it = step->children.insert(it, make_pair(c, new TrieNode()));
                it->second->parent = step;
            }
            step = it->second;
        }
        int diff = val - step->val;
        step->val += diff;
        
        while (step) {
            step->sum += diff;
            step = step->parent;
        }
    }
    
    int sum(string prefix) {
        auto step = root;
        for (auto c: prefix) {
            auto it = step->children.find(c);
            if (it == step->children.end()) {
                return 0;
            }
            step = it->second;
        }
        return step->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */