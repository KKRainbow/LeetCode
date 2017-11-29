// 谨记：出度为1即为叶节点
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        if (!n) return {};
        vector<set<int>> mat(n);
        set<int> leaves;
        for (auto& e: edges) {
            mat[e.first].insert(e.second);
            mat[e.second].insert(e.first);
        }
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i].size() == 1) {
                leaves.insert(i);
            }
        }
        while (n > 2) {
            set<int> newLeaves;
            for (auto& leaf: leaves) {
                auto pid = *mat[leaf].begin();
                auto& parent = mat[pid];
                parent.erase(leaf);
                if (parent.size() == 1) {
                    newLeaves.insert(pid);
                }
                n--;
            }
            leaves.swap(newLeaves);
        }
        return vector<int>(leaves.begin(), leaves.end());
    }
};