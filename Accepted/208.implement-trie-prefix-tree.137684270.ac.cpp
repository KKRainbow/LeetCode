class Trie {
    struct Node {
        Node* children[26];
        bool endFlag;
        Node() {
            memset(children, 0, sizeof(Node*) * 26);
        }
    } *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto step = root;
        for (auto c : word) {
            auto& tmp = step->children[c - 'a'];
            if (!tmp) {
                tmp = new Node;
            }
            step = tmp;
        }
        step->endFlag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto step = root;
        for (auto c : word) {
            step = step->children[c - 'a'];
            if (!step) return false;
        }
        return step->endFlag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto step = root;
        for (auto c : prefix) {
            step = step->children[c - 'a'];
            if (!step) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */