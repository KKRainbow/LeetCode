class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        int maxD = 60 * 24;
        for (auto& str : timePoints) {
            stringstream ss(str);
            string minStr, hourStr;
            getline(ss, hourStr, ':');
            getline(ss, minStr, ':');
            int min = atoi(minStr.c_str()), hour = atoi(hourStr.c_str());
            times.push_back(hour * 60 + min);
        }
        sort(times.begin(), times.end());
        times.push_back(times.front() + maxD);
        int minDiff = INT_MAX;
        for (int i = 1; i < times.size(); i++) {
            auto& a = times[i], & b = times[i - 1];
            int diff = min(a - b, maxD + (b - a));
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
};