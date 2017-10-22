class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        multimap<int, int> m;
        int res = INT_MAX;
        for (int i = 0; i < wall.size(); i++) {
            int w = wall[i][wall[i].size() - 1];
            m.insert(make_pair(w, i));
            wall[i].pop_back();
        }

        while (1) {
            int shortest = m.begin()->first;
            int idx = m.begin()->second;
            
            auto upper_it = m.upper_bound(shortest);
            
            int dis = distance(upper_it, m.end());
                        //cout << shortest << ',' << idx << ',' << dis << endl;
            
            if (wall[idx].size() == 0) break;
            res = min(res, dis);
            m.erase(m.begin());
            m.insert(make_pair(shortest + wall[idx][wall[idx].size() - 1], idx));
            wall[idx].pop_back();
        }
        //cout << endl;
        return res == INT_MAX ?  wall.size() : res;
    }
};