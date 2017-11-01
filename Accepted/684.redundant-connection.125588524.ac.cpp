class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> s(edges.size() + 1);
        for (int i = 0; i < s.size(); i++) {
            s[i] = i;
        }
        function<int(int)> findSet;
        findSet = [&s, &findSet](int node) {
            if (s[node] == node) return node;
            s[node] = findSet(s[node]);
            return s[node];
        };
        auto makeUnion = [&s, &findSet](int node1, int node2) {
            auto a = findSet(node1);
            auto b = findSet(node2);
            bool same = a ==b;
            s[a] = b;
            return same;
        };
        for (auto& edge: edges) {
            if (makeUnion(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};