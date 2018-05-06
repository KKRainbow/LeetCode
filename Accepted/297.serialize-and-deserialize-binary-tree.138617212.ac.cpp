/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    const int elen = sizeof(int) * 2;
private:
    string buildStr(int val, bool hasChildren, bool end = false) {
        int tmp[] = {
            val, 0
        };
        if (hasChildren) {
            tmp[1] = 1;
        }
        if (end) {
            tmp[1] = 2;
        }
        return string((char*)tmp, sizeof(int) * 2);
    }
    tuple<int, bool, bool> extract(const string& str, int pos) {
        auto data = str.data() + pos;
        int val = *(int*)data;
        int flag = *((int*)data + 1);
        bool hasChildren = flag == 1;
        bool end = flag == 2;
        return make_tuple(val, hasChildren, end);
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return string();
        string res;
        if (root->left) {
            res += buildStr(root->val, true) + serialize(root->left);
        } else {
            res += buildStr(root->val, false);
        }
        if (root->right) {
            res += serialize(root->right);
        } else {        
            res += buildStr(0, false, true);
        }
        return res;
    }
    
    tuple<TreeNode*, int> helper(const string& data, int pos) {
        int val;
        bool hc, end;
        tie(val, hc, end) = extract(data, pos);
        if (end) {
            return make_tuple(nullptr, pos + elen);
        }
        pos += elen;
        TreeNode *root = new TreeNode(val);
        if (hc) {
            tie(root->left, pos) = helper(data, pos);
        }
        tie(root->right, pos) = helper(data, pos);
        return make_tuple(root, pos);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        return get<0>(helper(data, 0));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
