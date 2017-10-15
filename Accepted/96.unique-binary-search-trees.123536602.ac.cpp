class Solution {
    map<int, int> res;
public:
    int numTrees(int n) {
        auto it = res.find(n);
        if (it != res.end()) {
            return it->second;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 0) {
            return 1;
        }
        int sum = 0;
        for (int i = 0; i < n ; i++) {
            sum += numTrees(i) * numTrees(n - i - 1);
        }
        
        res[n] = sum;
        return sum;
    }
};