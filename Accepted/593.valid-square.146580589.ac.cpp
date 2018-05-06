class Solution {
    int dist(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> tmp{p1, p2, p3, p4};
        for (int i = 0; i < 4; i++) {
            vector<int> dists(3);
            int idx = 0;
            for (int j = 0; j < 4; j++) {
                if (j == i) continue;
                dists[idx++] = this->dist(tmp[i], tmp[j]);
            }
            sort(dists.begin(), dists.end());
            if (dists[0] == 0 || dists[0] != dists[1] || dists[0] * 2 != dists[2]) {
                return false;
            }
        }
        return true;
    }
};
