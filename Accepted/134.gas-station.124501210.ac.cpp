class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> indices(gas.size(), -1), remain(gas.size());
        for (int i = 0; i < gas.size() * 2; i++) {
            int a = i % gas.size(), b = (i + gas.size() - 1) % gas.size();
            int re = remain[b] - cost[b] + gas[b];
            if (re >= remain[a]) {
                remain[a] = re;
                indices[a] = indices[b] == -1 ? b : indices[b];
            }
            if (i / gas.size() == 1 && indices[a] == -1) return -1;
        }
        return indices[0];
    }
};