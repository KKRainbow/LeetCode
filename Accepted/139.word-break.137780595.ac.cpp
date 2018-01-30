class Solution {
    struct Node {
        Node* children[26];
        bool endFlag = false;
        Node() {
            memset(children, 0, sizeof(Node*) * 26);
        }
    } *root;

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
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Node;
        for (const auto& str : wordDict) {
            insert(str);
        }
        vector<bool> vec(s.length() + 1, false);
        vec[s.length()] = true;
        for (int start = s.length() - 1; start >= 0; start--) {
            auto step = root;
            for (int cur = start; cur < s.length() && step; cur++) {
                step = step->children[s[cur] - 'a'];
                if (step && step->endFlag) {
                    vec[start] = vec[cur + 1];
                    if (vec[start]) break;
                }
            }
        }
        return vec[0];
    }
};