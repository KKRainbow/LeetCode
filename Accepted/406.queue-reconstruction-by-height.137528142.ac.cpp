class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        vector<int> rmq;
        vector<pair<int, int>> result;
        while (result.size() != people.size()) {
            bool flag = false;
            for (int i = 0; i < people.size(); i++) {
                auto &p = people[i];
                if (p.first < 0) continue;
                int bigThan = 0;
                auto it = lower_bound(rmq.begin(), rmq.end(), p.first);
                bigThan = rmq.end() - it;
                if (bigThan == p.second) {
                    result.push_back(p);
                    rmq.insert(it, p.first);
                    p.first = -1;
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                return result;
            }
        }
        return result;
    }
};